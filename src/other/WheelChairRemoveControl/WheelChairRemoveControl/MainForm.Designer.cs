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
            this.numericUpDownX = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.numericUpDownY = new System.Windows.Forms.NumericUpDown();
            this.label2 = new System.Windows.Forms.Label();
            this.buttonSteeringStart = new System.Windows.Forms.Button();
            this.numericUpDownAlpha = new System.Windows.Forms.NumericUpDown();
            this.buttonRestart = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.mainPictureBox)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownX)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownY)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownAlpha)).BeginInit();
            this.SuspendLayout();
            // 
            // mainPictureBox
            // 
            this.mainPictureBox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.mainPictureBox.Location = new System.Drawing.Point(279, 12);
            this.mainPictureBox.Name = "mainPictureBox";
            this.mainPictureBox.Size = new System.Drawing.Size(359, 346);
            this.mainPictureBox.TabIndex = 0;
            this.mainPictureBox.TabStop = false;
            this.mainPictureBox.Paint += new System.Windows.Forms.PaintEventHandler(this.mainPictureBox_Paint);
            // 
            // buttonLeft
            // 
            this.buttonLeft.Location = new System.Drawing.Point(146, 196);
            this.buttonLeft.Name = "buttonLeft";
            this.buttonLeft.Size = new System.Drawing.Size(39, 23);
            this.buttonLeft.TabIndex = 1;
            this.buttonLeft.Text = "<";
            this.buttonLeft.UseVisualStyleBackColor = true;
            this.buttonLeft.Click += new System.EventHandler(this.buttonLeft_Click);
            this.buttonLeft.KeyDown += new System.Windows.Forms.KeyEventHandler(this.KeyDown);
            this.buttonLeft.KeyUp += new System.Windows.Forms.KeyEventHandler(this.KeyUp);
            // 
            // buttonRight
            // 
            this.buttonRight.Location = new System.Drawing.Point(236, 196);
            this.buttonRight.Name = "buttonRight";
            this.buttonRight.Size = new System.Drawing.Size(39, 23);
            this.buttonRight.TabIndex = 2;
            this.buttonRight.Text = ">";
            this.buttonRight.UseVisualStyleBackColor = true;
            this.buttonRight.Click += new System.EventHandler(this.buttonRight_Click);
            this.buttonRight.KeyDown += new System.Windows.Forms.KeyEventHandler(this.KeyDown);
            this.buttonRight.KeyUp += new System.Windows.Forms.KeyEventHandler(this.KeyUp);
            // 
            // buttonUp
            // 
            this.buttonUp.Location = new System.Drawing.Point(191, 175);
            this.buttonUp.Name = "buttonUp";
            this.buttonUp.Size = new System.Drawing.Size(39, 23);
            this.buttonUp.TabIndex = 3;
            this.buttonUp.Text = "^";
            this.buttonUp.UseVisualStyleBackColor = true;
            this.buttonUp.KeyDown += new System.Windows.Forms.KeyEventHandler(this.KeyDown);
            this.buttonUp.KeyUp += new System.Windows.Forms.KeyEventHandler(this.KeyUp);
            this.buttonUp.MouseDown += new System.Windows.Forms.MouseEventHandler(this.buttonUp_MouseDown);
            this.buttonUp.MouseUp += new System.Windows.Forms.MouseEventHandler(this.buttonUp_MouseUp);
            // 
            // buttonDown
            // 
            this.buttonDown.Location = new System.Drawing.Point(191, 215);
            this.buttonDown.Name = "buttonDown";
            this.buttonDown.Size = new System.Drawing.Size(39, 23);
            this.buttonDown.TabIndex = 4;
            this.buttonDown.Text = "v";
            this.buttonDown.UseVisualStyleBackColor = true;
            this.buttonDown.KeyDown += new System.Windows.Forms.KeyEventHandler(this.KeyDown);
            this.buttonDown.KeyUp += new System.Windows.Forms.KeyEventHandler(this.KeyUp);
            this.buttonDown.MouseDown += new System.Windows.Forms.MouseEventHandler(this.buttonDown_MouseDown);
            this.buttonDown.MouseUp += new System.Windows.Forms.MouseEventHandler(this.buttonDown_MouseUp);
            // 
            // messageTextBox
            // 
            this.messageTextBox.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left)));
            this.messageTextBox.Location = new System.Drawing.Point(12, 120);
            this.messageTextBox.Name = "messageTextBox";
            this.messageTextBox.ReadOnly = true;
            this.messageTextBox.Size = new System.Drawing.Size(125, 238);
            this.messageTextBox.TabIndex = 5;
            this.messageTextBox.Text = "";
            this.messageTextBox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.KeyDown);
            this.messageTextBox.KeyUp += new System.Windows.Forms.KeyEventHandler(this.KeyUp);
            // 
            // ConnectButton
            // 
            this.ConnectButton.Location = new System.Drawing.Point(12, 68);
            this.ConnectButton.Name = "ConnectButton";
            this.ConnectButton.Size = new System.Drawing.Size(125, 23);
            this.ConnectButton.TabIndex = 6;
            this.ConnectButton.Text = "Connect";
            this.ConnectButton.UseVisualStyleBackColor = true;
            this.ConnectButton.Click += new System.EventHandler(this.ConnectButton_Click);
            this.ConnectButton.KeyDown += new System.Windows.Forms.KeyEventHandler(this.KeyDown);
            this.ConnectButton.KeyUp += new System.Windows.Forms.KeyEventHandler(this.KeyUp);
            // 
            // checkBoxConnected
            // 
            this.checkBoxConnected.AutoCheck = false;
            this.checkBoxConnected.AutoSize = true;
            this.checkBoxConnected.Location = new System.Drawing.Point(12, 97);
            this.checkBoxConnected.Name = "checkBoxConnected";
            this.checkBoxConnected.Size = new System.Drawing.Size(77, 17);
            this.checkBoxConnected.TabIndex = 8;
            this.checkBoxConnected.Text = "connected";
            this.checkBoxConnected.UseVisualStyleBackColor = true;
            this.checkBoxConnected.KeyDown += new System.Windows.Forms.KeyEventHandler(this.KeyDown);
            this.checkBoxConnected.KeyUp += new System.Windows.Forms.KeyEventHandler(this.KeyUp);
            // 
            // portComboBox
            // 
            this.portComboBox.FormattingEnabled = true;
            this.portComboBox.Location = new System.Drawing.Point(12, 41);
            this.portComboBox.Name = "portComboBox";
            this.portComboBox.Size = new System.Drawing.Size(125, 21);
            this.portComboBox.TabIndex = 9;
            // 
            // refreshPortsButton
            // 
            this.refreshPortsButton.Location = new System.Drawing.Point(12, 12);
            this.refreshPortsButton.Name = "refreshPortsButton";
            this.refreshPortsButton.Size = new System.Drawing.Size(125, 23);
            this.refreshPortsButton.TabIndex = 10;
            this.refreshPortsButton.Text = "Refresh Ports";
            this.refreshPortsButton.UseVisualStyleBackColor = true;
            this.refreshPortsButton.Click += new System.EventHandler(this.refreshPortsButton_Click);
            // 
            // numericUpDownX
            // 
            this.numericUpDownX.DecimalPlaces = 3;
            this.numericUpDownX.Increment = new decimal(new int[] {
            1,
            0,
            0,
            65536});
            this.numericUpDownX.Location = new System.Drawing.Point(146, 28);
            this.numericUpDownX.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
            this.numericUpDownX.Minimum = new decimal(new int[] {
            10000,
            0,
            0,
            -2147483648});
            this.numericUpDownX.Name = "numericUpDownX";
            this.numericUpDownX.Size = new System.Drawing.Size(113, 20);
            this.numericUpDownX.TabIndex = 11;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(143, 12);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(85, 13);
            this.label1.TabIndex = 12;
            this.label1.Text = "Move To (x/y/a)";
            // 
            // numericUpDownY
            // 
            this.numericUpDownY.DecimalPlaces = 3;
            this.numericUpDownY.Increment = new decimal(new int[] {
            1,
            0,
            0,
            65536});
            this.numericUpDownY.Location = new System.Drawing.Point(146, 54);
            this.numericUpDownY.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
            this.numericUpDownY.Minimum = new decimal(new int[] {
            10000,
            0,
            0,
            -2147483648});
            this.numericUpDownY.Name = "numericUpDownY";
            this.numericUpDownY.Size = new System.Drawing.Size(113, 20);
            this.numericUpDownY.TabIndex = 13;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(143, 159);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(82, 13);
            this.label2.TabIndex = 14;
            this.label2.Text = "Steering Control";
            // 
            // buttonSteeringStart
            // 
            this.buttonSteeringStart.Location = new System.Drawing.Point(146, 106);
            this.buttonSteeringStart.Name = "buttonSteeringStart";
            this.buttonSteeringStart.Size = new System.Drawing.Size(113, 23);
            this.buttonSteeringStart.TabIndex = 15;
            this.buttonSteeringStart.Text = "Start";
            this.buttonSteeringStart.UseVisualStyleBackColor = true;
            this.buttonSteeringStart.Click += new System.EventHandler(this.buttonSteeringStart_Click);
            // 
            // numericUpDownAlpha
            // 
            this.numericUpDownAlpha.DecimalPlaces = 2;
            this.numericUpDownAlpha.Increment = new decimal(new int[] {
            45,
            0,
            0,
            0});
            this.numericUpDownAlpha.Location = new System.Drawing.Point(146, 80);
            this.numericUpDownAlpha.Maximum = new decimal(new int[] {
            360,
            0,
            0,
            0});
            this.numericUpDownAlpha.Name = "numericUpDownAlpha";
            this.numericUpDownAlpha.Size = new System.Drawing.Size(113, 20);
            this.numericUpDownAlpha.TabIndex = 16;
            // 
            // buttonRestart
            // 
            this.buttonRestart.Location = new System.Drawing.Point(146, 259);
            this.buttonRestart.Name = "buttonRestart";
            this.buttonRestart.Size = new System.Drawing.Size(113, 23);
            this.buttonRestart.TabIndex = 17;
            this.buttonRestart.Text = "Restart";
            this.buttonRestart.UseVisualStyleBackColor = true;
            this.buttonRestart.Click += new System.EventHandler(this.buttonRestart_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(650, 370);
            this.Controls.Add(this.buttonRestart);
            this.Controls.Add(this.numericUpDownAlpha);
            this.Controls.Add(this.buttonSteeringStart);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.numericUpDownY);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.numericUpDownX);
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
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownX)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownY)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownAlpha)).EndInit();
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
        private System.Windows.Forms.NumericUpDown numericUpDownX;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.NumericUpDown numericUpDownY;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button buttonSteeringStart;
        private System.Windows.Forms.NumericUpDown numericUpDownAlpha;
        private System.Windows.Forms.Button buttonRestart;
    }
}

