namespace WheelChairRemoveControl
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.mainPictureBox = new System.Windows.Forms.PictureBox();
            this.buttonLeft = new System.Windows.Forms.Button();
            this.buttonRight = new System.Windows.Forms.Button();
            this.buttonUp = new System.Windows.Forms.Button();
            this.buttonDown = new System.Windows.Forms.Button();
            this.messageTextBox = new System.Windows.Forms.RichTextBox();
            this.ConnectButton = new System.Windows.Forms.Button();
            this.checkBoxConnected = new System.Windows.Forms.CheckBox();
            this.portComboBox = new System.Windows.Forms.ComboBox();
            this.refreshPortsButton = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.mainPictureBox)).BeginInit();
            this.SuspendLayout();
            // 
            // mainPictureBox
            // 
            this.mainPictureBox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.mainPictureBox.Location = new System.Drawing.Point(143, 12);
            this.mainPictureBox.Name = "mainPictureBox";
            this.mainPictureBox.Size = new System.Drawing.Size(472, 387);
            this.mainPictureBox.TabIndex = 0;
            this.mainPictureBox.TabStop = false;
            // 
            // buttonLeft
            // 
            this.buttonLeft.Location = new System.Drawing.Point(12, 36);
            this.buttonLeft.Name = "buttonLeft";
            this.buttonLeft.Size = new System.Drawing.Size(39, 23);
            this.buttonLeft.TabIndex = 1;
            this.buttonLeft.Text = "<";
            this.buttonLeft.UseVisualStyleBackColor = true;
            this.buttonLeft.Click += new System.EventHandler(this.driveLeftButtonClick);
            this.buttonLeft.KeyDown += new System.Windows.Forms.KeyEventHandler(this.button_KeyDown);
            this.buttonLeft.KeyUp += new System.Windows.Forms.KeyEventHandler(this.button_KeyUp);
            // 
            // buttonRight
            // 
            this.buttonRight.Location = new System.Drawing.Point(102, 36);
            this.buttonRight.Name = "buttonRight";
            this.buttonRight.Size = new System.Drawing.Size(39, 23);
            this.buttonRight.TabIndex = 2;
            this.buttonRight.Text = ">";
            this.buttonRight.UseVisualStyleBackColor = true;
            this.buttonRight.Click += new System.EventHandler(this.driveRightButtonClick);
            this.buttonRight.KeyDown += new System.Windows.Forms.KeyEventHandler(this.button_KeyDown);
            this.buttonRight.KeyUp += new System.Windows.Forms.KeyEventHandler(this.button_KeyUp);
            // 
            // buttonUp
            // 
            this.buttonUp.Location = new System.Drawing.Point(57, 15);
            this.buttonUp.Name = "buttonUp";
            this.buttonUp.Size = new System.Drawing.Size(39, 23);
            this.buttonUp.TabIndex = 3;
            this.buttonUp.Text = "^";
            this.buttonUp.UseVisualStyleBackColor = true;
            this.buttonUp.KeyDown += new System.Windows.Forms.KeyEventHandler(this.button_KeyDown);
            this.buttonUp.KeyUp += new System.Windows.Forms.KeyEventHandler(this.button_KeyUp);
            this.buttonUp.MouseDown += new System.Windows.Forms.MouseEventHandler(this.driveForwardStart);
            this.buttonUp.MouseUp += new System.Windows.Forms.MouseEventHandler(this.driveForwardEnd);
            // 
            // buttonDown
            // 
            this.buttonDown.Location = new System.Drawing.Point(57, 55);
            this.buttonDown.Name = "buttonDown";
            this.buttonDown.Size = new System.Drawing.Size(39, 23);
            this.buttonDown.TabIndex = 4;
            this.buttonDown.Text = "v";
            this.buttonDown.UseVisualStyleBackColor = true;
            this.buttonDown.KeyDown += new System.Windows.Forms.KeyEventHandler(this.button_KeyDown);
            this.buttonDown.KeyUp += new System.Windows.Forms.KeyEventHandler(this.button_KeyUp);
            this.buttonDown.MouseDown += new System.Windows.Forms.MouseEventHandler(this.driveBackwardStart);
            this.buttonDown.MouseUp += new System.Windows.Forms.MouseEventHandler(this.driveBackwardEnd);
            // 
            // messageTextBox
            // 
            this.messageTextBox.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left)));
            this.messageTextBox.Location = new System.Drawing.Point(12, 190);
            this.messageTextBox.Name = "messageTextBox";
            this.messageTextBox.ReadOnly = true;
            this.messageTextBox.Size = new System.Drawing.Size(125, 209);
            this.messageTextBox.TabIndex = 5;
            this.messageTextBox.Text = "";
            this.messageTextBox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.button_KeyDown);
            this.messageTextBox.KeyUp += new System.Windows.Forms.KeyEventHandler(this.button_KeyUp);
            // 
            // ConnectButton
            // 
            this.ConnectButton.Location = new System.Drawing.Point(12, 138);
            this.ConnectButton.Name = "ConnectButton";
            this.ConnectButton.Size = new System.Drawing.Size(125, 23);
            this.ConnectButton.TabIndex = 6;
            this.ConnectButton.Text = "Connect";
            this.ConnectButton.UseVisualStyleBackColor = true;
            this.ConnectButton.Click += new System.EventHandler(this.ConnectButton_Click);
            this.ConnectButton.KeyDown += new System.Windows.Forms.KeyEventHandler(this.button_KeyDown);
            this.ConnectButton.KeyUp += new System.Windows.Forms.KeyEventHandler(this.button_KeyUp);
            // 
            // checkBoxConnected
            // 
            this.checkBoxConnected.AutoCheck = false;
            this.checkBoxConnected.AutoSize = true;
            this.checkBoxConnected.Location = new System.Drawing.Point(12, 167);
            this.checkBoxConnected.Name = "checkBoxConnected";
            this.checkBoxConnected.Size = new System.Drawing.Size(77, 17);
            this.checkBoxConnected.TabIndex = 8;
            this.checkBoxConnected.Text = "connected";
            this.checkBoxConnected.UseVisualStyleBackColor = true;
            this.checkBoxConnected.KeyDown += new System.Windows.Forms.KeyEventHandler(this.button_KeyDown);
            this.checkBoxConnected.KeyUp += new System.Windows.Forms.KeyEventHandler(this.button_KeyUp);
            // 
            // portComboBox
            // 
            this.portComboBox.FormattingEnabled = true;
            this.portComboBox.Location = new System.Drawing.Point(12, 111);
            this.portComboBox.Name = "portComboBox";
            this.portComboBox.Size = new System.Drawing.Size(125, 21);
            this.portComboBox.TabIndex = 9;
            this.portComboBox.Text = "COM11";
            // 
            // refreshPortsButton
            // 
            this.refreshPortsButton.Location = new System.Drawing.Point(12, 82);
            this.refreshPortsButton.Name = "refreshPortsButton";
            this.refreshPortsButton.Size = new System.Drawing.Size(125, 23);
            this.refreshPortsButton.TabIndex = 10;
            this.refreshPortsButton.Text = "Refresh Ports";
            this.refreshPortsButton.UseVisualStyleBackColor = true;
            this.refreshPortsButton.Click += new System.EventHandler(this.refreshPortsButton_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(627, 411);
            this.Controls.Add(this.refreshPortsButton);
            this.Controls.Add(this.portComboBox);
            this.Controls.Add(this.checkBoxConnected);
            this.Controls.Add(this.ConnectButton);
            this.Controls.Add(this.messageTextBox);
            this.Controls.Add(this.buttonDown);
            this.Controls.Add(this.buttonUp);
            this.Controls.Add(this.buttonRight);
            this.Controls.Add(this.buttonLeft);
            this.Controls.Add(this.mainPictureBox);
            this.Name = "MainForm";
            this.Text = "Wheel Chair Remote Control";
            ((System.ComponentModel.ISupportInitialize)(this.mainPictureBox)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox mainPictureBox;
        private System.Windows.Forms.Button buttonLeft;
        private System.Windows.Forms.Button buttonRight;
        private System.Windows.Forms.Button buttonUp;
        private System.Windows.Forms.Button buttonDown;
        private System.Windows.Forms.RichTextBox messageTextBox;
        private System.Windows.Forms.Button ConnectButton;
        private System.Windows.Forms.CheckBox checkBoxConnected;
        private System.Windows.Forms.ComboBox portComboBox;
        private System.Windows.Forms.Button refreshPortsButton;
    }
}

