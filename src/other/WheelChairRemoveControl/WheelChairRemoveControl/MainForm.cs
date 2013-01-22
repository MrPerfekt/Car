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
        CarSerialConnection SerialConnection { get;set;}
        Color selectedCol = Color.Green,
            unselectedCol = Button.DefaultBackColor;

        public MainForm()
        {
            SerialConnection = new CarSerialConnection();
            InitializeComponent();
            refreshPorts();
            SerialConnection.ConnectionStateChanged += new EventHandler(serialConnection_ConnectionStateChanged);
            SerialConnection.CurPowDirChanged += new EventHandler(serialConnection_CurPowDirChanged);
            SerialConnection.CurSteerDirChanged += new EventHandler(serialConnection_CurSteerDirChanged);
            SerialConnection.messageOccured += new MessageEventHandler(SerialConnection_messageOccured);
        }

        void SerialConnection_messageOccured(object sender, MessageEventArgs eventArgs)
        {
            this.Invoke(new MethodInvoker(delegate { SetMessage(eventArgs.Message); }));
            //SetMessage(eventArgs.Message);
        }

        void serialConnection_ConnectionStateChanged(object sender, EventArgs e)
        {
            checkBoxConnected.Checked = SerialConnection.Connected;
            ConnectButton.Text = SerialConnection.Connected ? "Disconnect" : "Connect";
        }
        void serialConnection_CurPowDirChanged(object sender, EventArgs e)
        {
            buttonUp.BackColor = buttonDown.BackColor = unselectedCol;
            if (SerialConnection.CurPowDir == PowerDirection.forward)
                buttonUp.BackColor = selectedCol;
            else if (SerialConnection.CurPowDir == PowerDirection.backward)
                buttonDown.BackColor = selectedCol;
        }
        void serialConnection_CurSteerDirChanged(object sender, EventArgs e)
        {
            buttonRight.BackColor = buttonLeft.BackColor = unselectedCol;
            if (SerialConnection.CurSteerDir == SteeringDirection.left)
                buttonLeft.BackColor = selectedCol;
            else if (SerialConnection.CurSteerDir == SteeringDirection.right)
                buttonRight.BackColor = selectedCol;
        }

        private void SetMessage(string message)
        {
            messageTextBox.Text = message + "\n" + messageTextBox.Text;
        }

        //!
        //! Settings and control
        //!
        private void ConnectButton_Click(object sender, EventArgs e)
        {
            try
            {
                bool connectedBefore = SerialConnection.Connected;
                if (!connectedBefore)
                    SerialConnection.Connect((string)portComboBox.SelectedItem);
                else
                    SerialConnection.Disconnect();
            }
            catch (Exception exc)
            {
                SetMessage(exc.Message);
            }
        }
        private void refreshPorts()
        {
            portComboBox.DataSource = SerialPort.GetPortNames();
        }
        private void refreshPortsButton_Click(object sender, EventArgs e)
        {
            refreshPorts();
        }
        //!
        //! Target
        //!
        private void buttonSteeringStart_Click(object sender, EventArgs e)
        {
            SerialConnection.SendTarget(new OrientedCoordinates(){
                X = (float)numericUpDownX.Value * 1000, 
                Y = (float)numericUpDownY.Value * 1000,
                Alpha = (float)(((float)numericUpDownAlpha.Value)*Math.PI/180)
            });
        }
        //!
        //! Key Steering
        //!
        Keys lastKeyDown = Keys.Escape;
        private void KeyDown(object sender, KeyEventArgs e)
        {
            if (lastKeyDown == e.KeyCode) return;
            lastKeyDown = e.KeyCode;
            switch (e.KeyCode)
            {
                case Keys.W:
                case Keys.Up:
                    SerialConnection.CurPowDir = PowerDirection.forward;
                    break;
                case Keys.S:
                case Keys.Down:
                    SerialConnection.CurPowDir = PowerDirection.backward;
                    break;
                case Keys.A:
                case Keys.Left:
                    SerialConnection.CurSteerDir = SteeringDirection.left;
                    break;
                case Keys.D:
                case Keys.Right:
                    SerialConnection.CurSteerDir = SteeringDirection.right;
                    break;
            }
            SerialConnection.sendMotion();
        }
        private void KeyUp(object sender, KeyEventArgs e)
        {
            lastKeyDown = Keys.Escape;
            switch (e.KeyCode)
            {
                case Keys.W:
                case Keys.Up:
                case Keys.S:
                case Keys.Down:
                    SerialConnection.CurPowDir = PowerDirection.stop;
                    break;
                case Keys.A:
                case Keys.Left:
                case Keys.D:
                case Keys.Right:
                    SerialConnection.CurSteerDir = SteeringDirection.straight;
                    break;
                default:
                    break;
            }
            SerialConnection.sendMotion();
        }
        //!
        //! Button Steering
        //!
        private void buttonLeft_Click(object sender, EventArgs e)
        {
            if (SerialConnection.CurSteerDir == SteeringDirection.left)
                SerialConnection.CurSteerDir = SteeringDirection.straight;
            else
                SerialConnection.CurSteerDir = SteeringDirection.left;
        }
        private void buttonRight_Click(object sender, EventArgs e)
        {
            if (SerialConnection.CurSteerDir == SteeringDirection.right)
                SerialConnection.CurSteerDir = SteeringDirection.straight;
            else
                SerialConnection.CurSteerDir = SteeringDirection.right;
        }
        private void buttonUp_MouseDown(object sender, MouseEventArgs e)
        {
            SerialConnection.CurPowDir = PowerDirection.forward;
        }
        private void buttonUp_MouseUp(object sender, MouseEventArgs e)
        {
            SerialConnection.CurPowDir = PowerDirection.stop;
        }
        private void buttonDown_MouseDown(object sender, MouseEventArgs e)
        {
            SerialConnection.CurPowDir = PowerDirection.backward;
        }
        private void buttonDown_MouseUp(object sender, MouseEventArgs e)
        {
            SerialConnection.CurPowDir = PowerDirection.stop;
        }
        //!
        //! Painging
        //!
        private void mainPictureBox_Paint(object sender, PaintEventArgs e)
        {
            const float size = 10;
            Graphics g = e.Graphics;
            foreach (var p in SerialConnection.FoundObjects)
            {
                g.FillEllipse(new SolidBrush(Color.Black),p.X - size / 2,p.Y - size/2,size,size);
            }
        }

        private void buttonRestart_Click(object sender, EventArgs e)
        {
            SerialConnection.sendRestart();
        }
    }
}
