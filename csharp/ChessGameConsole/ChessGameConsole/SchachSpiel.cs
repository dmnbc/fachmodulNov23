using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace ChessGameConsole
{
    public class SchachSpiel
    {
        private SpielBrett brett;

        public SchachSpiel()
        {
            brett = new SpielBrett(8); // Standard 8x8 Schachbrett
        }

        public void StarteSpiel()
        {
            brett.ZeichneBrett();
        }
    }
}
