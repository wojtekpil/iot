using System;
using System.IO;
using System.Net.Sockets;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CzujnikTemperatury
{
    class TcpLink : Link
    {
        private TcpClient tcpclnt;
        private Func<string> reciveCallback;
        public override void connect(string conf)
        {
            tcpclnt = new TcpClient();
            string[] confs = conf.Split(':');
            if(confs.Length != 2)
            {
                throw new Exception("Nie rozoznano adresu serwera");
            }
            tcpclnt.Connect(confs[0], int.Parse(confs[1]));
            Stream stm = tcpclnt.GetStream();
            ASCIIEncoding asen = new ASCIIEncoding();
            byte[] ba = asen.GetBytes("1234\r");
            stm.Write(ba, 0, ba.Length);
            ba = asen.GetBytes("tajne_haslo\r");
            stm.Write(ba, 0, ba.Length);

        }

        public override void disconnect()
        {
            tcpclnt.Close();
        }

        public override void onRecive(Func<string> fun)
        {
            reciveCallback = fun;
        }

        public override void send(string msg)
        {
            Stream stm = tcpclnt.GetStream();
            ASCIIEncoding asen = new ASCIIEncoding();
            byte[] ba = asen.GetBytes(msg+ "\r");
            stm.Write(ba, 0, ba.Length);
        }
    }
}
