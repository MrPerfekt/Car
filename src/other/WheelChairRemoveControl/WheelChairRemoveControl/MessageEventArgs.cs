using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace WheelChairRemoveControl
{
    delegate void MessageEventHandler(object sender, MessageEventArgs eventArgs);
    public class MessageEventArgs : EventArgs
    {
        public string Message { get; set; }
        public MessageEventArgs(string message)
        {
            Message = message;
        }
    }
}
