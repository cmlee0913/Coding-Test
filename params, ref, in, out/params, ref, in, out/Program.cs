using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace params__ref__in__out
{
    public class Example
    {
        public string a;
        public string b;

        void Example(string str) {
            a = str;
            b = a;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            // 인스턴스 생성과 동시에 a에 문자열 대입
            Example ex = new Example("안녕하세요");

            Console.WriteLine("{0}", ex.a);

            ex.b = "반갑습니다.";

            Console.WriteLine("{0}, {1}", ex.a, ex.b);
        }
    }
}
