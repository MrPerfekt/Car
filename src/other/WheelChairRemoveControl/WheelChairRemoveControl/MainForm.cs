using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO.Ports;

namespace WheelChairRemoveControl
{
    public partial class MainForm : Form
    {
        static const string cmdStop = "S";
        static const string cmdDrive = "D";//! DR<Forward/Backward><Stright/Left/Right> a.e. DRFL


        private bool curConnect;

        public bool Connected
        {
            get { return curConnect; }
            set
            {
                checkBoxConnected.Checked = value;
                ConnectButton.Text = value ? "Disconnect" : "Connect";
                curConnect = value;
            }
        }
        
        private Direction curDir = Direction.stright;
        Color selectedCol = Color.Green,
            unselectedCol = Button.DefaultBackColor;
        public Direction CurDir
        {
            get { return curDir; }
            set
            {
                if (curDir == value)
                    curDir = Direction.stright;
                else
                    curDir = value;
                buttonRight.BackColor = buttonLeft.BackColor = unselectedCol;
                if (curDir == Direction.left)
                    buttonLeft.BackColor = selectedCol;
                else if (curDir == Direction.right)
                    buttonRight.BackColor = selectedCol;
            }
        }
        public string CurDirString()
        {
            switch (CurDir)
            {
                case Direction.stright:
                    return "S";
                case Direction.left:
                    return "L";
                case Direction.right:
                    return "R";
                default:
                    return "";
            }
        }

        SerialPort serialPort;
        

        public MainForm()
        {
            InitializeComponent();
            refreshPorts();
        }

        private void SendText(string text)
        {
            if (serialPort != null && serialPort.IsOpen)
            {
                serialPort.WriteLine(text);
            }
            else
            {
                Connected = false;
            }
        }

        private void driveForwardStart(object sender, EventArgs e)
        {
            buttonUp.BackColor = selectedCol;
            SendText(cmdDrive + CurDirString() + "F");
        }

        private void driveForwardEnd(object sender, EventArgs e)
        {
            buttonUp.BackColor = unselectedCol;
            SendText(cmdStop);
        }

        private void driveBackwardStart(object sender, EventArgs e)
        {
            buttonDown.BackColor = selectedCol;
            SendText(cmdDrive + CurDirString() + "B");
        }

        private void driveBackwardEnd(object sender, EventArgs e)
        {
            buttonDown.BackColor = unselectedCol;
            SendText(cmdStop);
        }

        private void driveRightButtonClick(object sender, EventArgs e)
        {
            CurDir = Direction.right;
        }

        private void driveLeftButtonClick(object sender, EventArgs e)
        {
            CurDir = Direction.left;
        }

        private void SetMessage(string message)
        {
            messageTextBox.Text = message + "\n" + messageTextBox.Text; 
        }

        private void ConnectButton_Click(object sender, EventArgs e)
        {
            bool connectedBefore = Connected;
            Connected = false;
            if (serialPort != null)
            {
                if (serialPort.IsOpen)
                    serialPort.Close();
                serialPort.Dispose();
            }
            if (!connectedBefore)
            {
                serialPort = new SerialPort(portComboBox.SelectedText, 9600);
                try
                {
                    serialPort.Open();
                }
                catch (Exception exc)
                {
                    SetMessage(exc.Message);
                    return;
                }
                Connected = true;
                serialPort.DataReceived += new SerialDataReceivedEventHandler(serialPort_DataReceived);
            }
        }

        void serialPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            this.Invoke(new MethodInvoker(delegate { SetMessage("Received: " + serialPort.ReadExisting()); }));
        }

        Keys lastKeyDown = Keys.Escape;
        private void button_KeyDown(object sender, KeyEventArgs e)
        {
            if (lastKeyDown == e.KeyCode) return;
            lastKeyDown = e.KeyCode;
            switch (e.KeyCode)
            {
                case Keys.W:
                case Keys.Up:
                    driveForwardStart(sender, e);
                    break;
                case Keys.S:
                case Keys.Down:
                    driveBackwardStart(sender, e);
                    break;
                case Keys.A:
                case Keys.Left:
                    CurDir = Direction.left;
                    break;
                case Keys.D:
                case Keys.Right:
                    CurDir = Direction.right;
                    break;
            }
        }

        private void button_KeyUp(object sender, KeyEventArgs e)
        {
            lastKeyDown = Keys.Escape;
            switch (e.KeyCode)
            {
                case Keys.W:
                case Keys.Up:
                    driveForwardEnd(sender, e);
                    break;
                case Keys.S:
                case Keys.Down:
                    driveBackwardEnd(sender, e);
                    break;
                case Keys.A:
                case Keys.Left:
                case Keys.D:
                case Keys.Right:
                    CurDir = Direction.stright;
                    break;
                default:
                    break;
            }
        }

        private void refreshPortsButton_Click(object sender, EventArgs e)
        {
            refreshPorts();
        }

        private void refreshPorts()
        {
            portComboBox.DataSource = SerialPort.GetPortNames();
        }
    }
}
