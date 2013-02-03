#define NDUMMY

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO.Ports;
using System.Drawing;


namespace WheelChairRemoveControl
{
    class CarSerialConnection
    {
        const string cmdRestart = "R";
        const string cmdStop = "S";
        const string cmdDrive = "D";//! D<Forward/Backward><Stright/Left/Right> a.e. DRFL
        const string cmdTarget = "T";//! T<X>/<Y>

        public CarSerialConnection()
        {
            FoundObjects = new List<Coordinates>();
            MyPositions = new List<OrientedCoordinates>();
        }

        public event MessageEventHandler messageOccured;
        public event EventHandler ConnectionStateChanged;
        private bool curConnect;
        public bool Connected
        {
            get { return curConnect; }
            set
            {
                if (Connected == value) return;
                curConnect = value;
                if (ConnectionStateChanged != null)
                    ConnectionStateChanged.Invoke(null,null);
            }
        }

        public event EventHandler CurSteerDirChanged;
        private SteeringDirection curSteerDir = SteeringDirection.straight;
        public SteeringDirection CurSteerDir
        {
            get { return curSteerDir; }
            set
            {
                if (CurSteerDir == value) return;
                curSteerDir = value;
                if (CurSteerDirChanged != null)
                    CurSteerDirChanged.Invoke(null, null);
            }
        }
        public string CurSteerDirString()
        {
            switch (CurSteerDir)
            {
                case SteeringDirection.straight:
                    return "S"; //! Straight
                case SteeringDirection.left:
                    return "L"; //! Left
                case SteeringDirection.right:
                    return "R"; //! Right
                default:
                    return "";
            }
        }
        public event EventHandler CurPowDirChanged;
        private PowerDirection curPowDir = PowerDirection.stop;
        public PowerDirection CurPowDir
        {
            get { return curPowDir; }
            set
            {
                if (CurPowDir == value) return;
                curPowDir = value;
                if (CurPowDirChanged != null)
                    CurPowDirChanged.Invoke(null, null);
            }
        }
        public string CurPowDirString()
        {
            switch (CurPowDir)
            {
                case PowerDirection.stop:
                    return "S"; //! Stop
                case PowerDirection.forward:
                    return "F"; //! Forward
                case PowerDirection.backward:
                    return "B"; //! Backward
                default:
                    return "";
            }
        }

        //!
        //! Connection
        //!
#if DUMMY
        DummySerialPort serialPort;
#else
        SerialPort serialPort;
#endif

        public void Connect(string port)
        {
#if DUMMY
            serialPort = new DummySerialPort(port, 9600);
#else
            serialPort = new SerialPort(port, 9600);
#endif
            try
            {
                serialPort.Open();
            }
            catch (Exception exc)
            {
                throw exc;
            }
            Connected = true;
            serialPort.WriteTimeout = serialPort.ReadTimeout = 500;
            serialPort.DataReceived += new SerialDataReceivedEventHandler(serialPort_DataReceived);
        }
        public void Disconnect()
        {
            Connected = false;
            if (serialPort != null)
            {
                if (serialPort.IsOpen)
                    serialPort.Close();
                serialPort.Dispose();
            }
        }
        private void SendText(string text)
        {
            if (serialPort != null && serialPort.IsOpen)
                try
                {
                    serialPort.WriteLine(text);
                    return;
                }
                catch (Exception e)
                {
                }
            Connected = false;
        }
        public void sendMotion()
        {
            if (CurPowDir == PowerDirection.stop)
                SendText(cmdStop);
            else
                SendText(cmdDrive + CurPowDirString() + CurSteerDirString());
        }
        //!
        //! Send Target
        //!
        internal void SendTarget(OrientedCoordinates point)
        {
            const string format = "0.######";
            SendText(cmdTarget + point.X.ToString(format) + "/" + point.Y.ToString(format) + "/" + point.Alpha.ToString(format));
        }
        //!
        //! Send Restart
        //!
        internal void sendRestart()
        {
            SendText(cmdRestart);
            MyPositions.Clear();
            FoundObjects.Clear();
        }
        //!
        //! Receive Data
        //!
        string rawdata;
        void serialPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            try
            {
                rawdata += serialPort.ReadExisting().Trim().Replace(" ", "").Replace(".",",");
                string[] splittedString = rawdata.Split(';');
                rawdata = splittedString[splittedString.Length - 1];
                for (int i = 0; i < splittedString.Length-1; i++)
                {
                    string data = splittedString[i];
                    string sendData = data.Remove(0, 1);
                    if (data.StartsWith("O")) //! Objects of the environment
                        receiveObjects(sendData);
                    else if (data.StartsWith("P")) //! Own Position
                        receivePosition(sendData);
                    else if (messageOccured != null)
                        messageOccured(this, new MessageEventArgs(data));
                }
            }
            catch (Exception ex)
            {
            }
        }
        //!
        //! Objects Received
        //!
        public event EventHandler ObjectsReceived;
        public List<Coordinates> FoundObjects { get; set; }
        void receiveObjects(string obj)
        {
            string[] parts = obj.Split('/');
            FoundObjects.Add(new Coordinates()
            {
                X = float.Parse(parts[0]),
                Y = float.Parse(parts[1])
            });
            if (ObjectsReceived != null)
                ObjectsReceived(this,null);
        }
        //!
        //! Positions Received
        //!
        public event EventHandler PositionsReceived;
        public List<OrientedCoordinates> MyPositions { get; set; }
        void receivePosition(string point)
        {
            string[] parts = point.Split('/');
            MyPositions.Add(new OrientedCoordinates()
            {
                X = float.Parse(parts[0]),
                Y = float.Parse(parts[1]),
                Alpha = float.Parse(parts[2])
            });
            if (PositionsReceived != null)
                PositionsReceived(this,null);
        }
    }
}
