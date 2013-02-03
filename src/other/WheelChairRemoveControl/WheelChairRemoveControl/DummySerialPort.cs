using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO.Ports;

namespace WheelChairRemoveControl
{
    public class DummySerialPort
    {
        public int ReadTimeout { get; set; }
        public int WriteTimeout { get; set; }
        public bool IsOpen { get; set; }

        public SerialDataReceivedEventHandler DataReceived { get; set; }

        public DummySerialPort(string port, int baud)
        {
            IsOpen = false;
        }

        public void Open()
        {
            IsOpen = true;
        }
        public string ReadExisting()
        {
            return "";
        }
        public void Close()
        {
            IsOpen = false;
        }
        public void Dispose()
        {
        }
        public void WriteLine(string text)
        {
        }
    }
}
