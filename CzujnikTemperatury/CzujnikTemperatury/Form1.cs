using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CzujnikTemperatury
{
    public partial class Form1 : Form
    {
        private Link link;
        private bool connected = false;
        public Form1()
        {
            InitializeComponent();
            link = new TcpLink();
        }

        private void connectButton_Click(object sender, EventArgs e)
        {
            if(connected == false)
            {
                try
                {
                    link.connect(serverAdressBox.Text);
                    toolStripStatus.Text = "Połączono";
                    connectButton.Text = "Rozłącz";
                    connected = true;
                }
                catch (Exception ex)
                {
                    toolStripStatus.Text = "Wystąpił problem z połączeniem";
                }
            } else
            {
                try
                {
                    link.disconnect();
                    toolStripStatus.Text = "Rozłączono";
                    connectButton.Text = "Połącz";
                    connected = false;
                }
                catch (Exception ex)
                {
                    toolStripStatus.Text = "Wystąpił problem z rozłączeniem";
                }
            }
           
            
        }

        private void TempButton_Click(object sender, EventArgs e)
        {
            string tempVal = tempValue.Value.ToString();
            link.send("temp=" + tempVal);
        }

        private void HumButton_Click(object sender, EventArgs e)
        {
            string humVal = humValue.Value.ToString();
            link.send("hum=" + humVal);
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            try
            {
                link.disconnect();
                connected = false;
            }
            catch (Exception ex)
            {
            }
        }
    }
}
