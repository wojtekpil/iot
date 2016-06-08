namespace CzujnikTemperatury
{
    partial class Form1
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
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.connectButton = new System.Windows.Forms.Button();
            this.serverAdressBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.tempGroupBox = new System.Windows.Forms.GroupBox();
            this.TempButton = new System.Windows.Forms.Button();
            this.tempValue = new System.Windows.Forms.NumericUpDown();
            this.label2 = new System.Windows.Forms.Label();
            this.humGroupBox = new System.Windows.Forms.GroupBox();
            this.HumButton = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.humValue = new System.Windows.Forms.NumericUpDown();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.toolStripStatus = new System.Windows.Forms.ToolStripStatusLabel();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.tempGroupBox.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.tempValue)).BeginInit();
            this.humGroupBox.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.humValue)).BeginInit();
            this.statusStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox1.Controls.Add(this.connectButton);
            this.groupBox1.Controls.Add(this.serverAdressBox);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Location = new System.Drawing.Point(13, 13);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(300, 78);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Konfiguracja";
            // 
            // connectButton
            // 
            this.connectButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.connectButton.Location = new System.Drawing.Point(221, 46);
            this.connectButton.Name = "connectButton";
            this.connectButton.Size = new System.Drawing.Size(75, 23);
            this.connectButton.TabIndex = 2;
            this.connectButton.Text = "Połącz";
            this.connectButton.UseVisualStyleBackColor = true;
            this.connectButton.Click += new System.EventHandler(this.connectButton_Click);
            // 
            // serverAdressBox
            // 
            this.serverAdressBox.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.serverAdressBox.Location = new System.Drawing.Point(88, 20);
            this.serverAdressBox.Name = "serverAdressBox";
            this.serverAdressBox.Size = new System.Drawing.Size(206, 20);
            this.serverAdressBox.TabIndex = 1;
            this.serverAdressBox.Text = "127.0.0.1:1234";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 23);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(74, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Adres serwera";
            // 
            // splitContainer1
            // 
            this.splitContainer1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.splitContainer1.Location = new System.Drawing.Point(13, 97);
            this.splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.tempGroupBox);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.humGroupBox);
            this.splitContainer1.Size = new System.Drawing.Size(300, 92);
            this.splitContainer1.SplitterDistance = 149;
            this.splitContainer1.TabIndex = 1;
            // 
            // tempGroupBox
            // 
            this.tempGroupBox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tempGroupBox.Controls.Add(this.TempButton);
            this.tempGroupBox.Controls.Add(this.tempValue);
            this.tempGroupBox.Controls.Add(this.label2);
            this.tempGroupBox.Location = new System.Drawing.Point(4, 4);
            this.tempGroupBox.Name = "tempGroupBox";
            this.tempGroupBox.Size = new System.Drawing.Size(142, 85);
            this.tempGroupBox.TabIndex = 0;
            this.tempGroupBox.TabStop = false;
            this.tempGroupBox.Text = "Temperatura";
            // 
            // TempButton
            // 
            this.TempButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.TempButton.Location = new System.Drawing.Point(61, 59);
            this.TempButton.Name = "TempButton";
            this.TempButton.Size = new System.Drawing.Size(75, 23);
            this.TempButton.TabIndex = 5;
            this.TempButton.Text = "Wyślij";
            this.TempButton.UseVisualStyleBackColor = true;
            this.TempButton.Click += new System.EventHandler(this.TempButton_Click);
            // 
            // tempValue
            // 
            this.tempValue.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tempValue.Location = new System.Drawing.Point(9, 33);
            this.tempValue.Name = "tempValue";
            this.tempValue.Size = new System.Drawing.Size(127, 20);
            this.tempValue.TabIndex = 4;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(6, 16);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(47, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Wartość";
            // 
            // humGroupBox
            // 
            this.humGroupBox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.humGroupBox.Controls.Add(this.HumButton);
            this.humGroupBox.Controls.Add(this.label3);
            this.humGroupBox.Controls.Add(this.humValue);
            this.humGroupBox.Location = new System.Drawing.Point(4, 1);
            this.humGroupBox.Name = "humGroupBox";
            this.humGroupBox.Size = new System.Drawing.Size(138, 88);
            this.humGroupBox.TabIndex = 0;
            this.humGroupBox.TabStop = false;
            this.humGroupBox.Text = "Wilgotność";
            // 
            // HumButton
            // 
            this.HumButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.HumButton.Location = new System.Drawing.Point(57, 62);
            this.HumButton.Name = "HumButton";
            this.HumButton.Size = new System.Drawing.Size(75, 23);
            this.HumButton.TabIndex = 8;
            this.HumButton.Text = "Wyślij";
            this.HumButton.UseVisualStyleBackColor = true;
            this.HumButton.Click += new System.EventHandler(this.HumButton_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(6, 19);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(47, 13);
            this.label3.TabIndex = 6;
            this.label3.Text = "Wartość";
            // 
            // humValue
            // 
            this.humValue.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.humValue.Location = new System.Drawing.Point(9, 36);
            this.humValue.Name = "humValue";
            this.humValue.Size = new System.Drawing.Size(123, 20);
            this.humValue.TabIndex = 7;
            // 
            // statusStrip1
            // 
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripStatus});
            this.statusStrip1.Location = new System.Drawing.Point(0, 192);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(325, 22);
            this.statusStrip1.TabIndex = 2;
            this.statusStrip1.Text = "tekst";
            // 
            // toolStripStatus
            // 
            this.toolStripStatus.Name = "toolStripStatus";
            this.toolStripStatus.Size = new System.Drawing.Size(76, 17);
            this.toolStripStatus.Text = "Rozłączono...";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(325, 214);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.splitContainer1);
            this.Controls.Add(this.groupBox1);
            this.MinimumSize = new System.Drawing.Size(225, 253);
            this.Name = "Form1";
            this.Text = "Tester Systemu";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.tempGroupBox.ResumeLayout(false);
            this.tempGroupBox.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.tempValue)).EndInit();
            this.humGroupBox.ResumeLayout(false);
            this.humGroupBox.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.humValue)).EndInit();
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox serverAdressBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button connectButton;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.GroupBox tempGroupBox;
        private System.Windows.Forms.GroupBox humGroupBox;
        private System.Windows.Forms.Button TempButton;
        private System.Windows.Forms.NumericUpDown tempValue;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button HumButton;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.NumericUpDown humValue;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatus;
    }
}

