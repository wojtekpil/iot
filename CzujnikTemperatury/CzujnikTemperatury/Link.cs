using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CzujnikTemperatury
{
    abstract class Link
    {
        public abstract void connect(string conf);
        public abstract void send(String msg);
        public abstract void onRecive(Func<string> fun);
        public abstract void disconnect();
    }
}
