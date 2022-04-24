using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace params__ref__in__out
{
    class Example1
    {
        // array
        public int[] a = { 1, 2, 3, 4, 5 };
        public int[] b;
    }

    class Example2
    {
        // string
        public string a = "스트링입니다.";
        public string b;
    }

    class Example3
    {
        // object
        public object a = "다이나믹도 새로 생성됩니다.";
        public object b;
    }

    class Example4
    {
        // class
        public int a = 10;
    }

    class Program
    {
        static void Main(string[] args)
        {
            // 인스턴스 생성
            Example1 ex1 = new Example1();

            // 객체 참조
            ex1.b = ex1.a;
            Console.WriteLine("{0}, {1}", ex1.a[1], ex1.b[1]);

            // b의 값 변경
            ex1.b[1] = 10;
            Console.WriteLine("{0}, {1}", ex1.a[1], ex1.b[1]);

            // 인스턴스를 새로 생성하면 연결이 끊어진다.
            ex1.b = new int[]{ 6, 7, 8, 9, 10 };

            ex1.b[1] = 30;
            Console.WriteLine("{0}, {1}", ex1.a[1], ex1.b[1]);


            // 인스턴스 생성
            Example2 ex2 = new Example2();

            Console.WriteLine("{0}", ex2.a);

            // 객체 참조
            ex2.b = ex2.a;
            // 문자열은 new를 사용하지 않아도 새 객체를 생성하는 것으로 취급한다.
            ex2.b = "저는 새로 생성됩니다.";

            Console.WriteLine("{0}, {1}", ex2.a, ex2.b);


            // 인스턴스 생성
            Example3 ex3 = new Example3();

            Console.WriteLine("{0}", ex3.a);

            // 객체 참조
            ex3.b = ex3.a;
            Console.WriteLine("{0}, {1}", ex3.a, ex3.b);
            // b의 값 변경. dynamic은 타입 캐스팅도 가능하다.
            ex3.b = 777;

            Console.WriteLine("{0}, {1}", ex3.a, ex3.b);


            // 인스턴스 생성
            Example4 ex4_1 = new Example4();

            // 객체 참조
            Example4 ex4_2 = ex4_1;
            Console.WriteLine("{0}, {1}", ex4_1.a, ex4_2.a);

            // ex4_2의 값 변경
            ex4_2.a = 20;

            Console.WriteLine("{0}, {1}", ex4_1.a, ex4_2.a);
        }
    }
}
