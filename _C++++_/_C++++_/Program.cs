using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _C_____
{
    // 싱글톤 객체는 public으로 선언.
    public class SingletonEx
    {
        // 전역 선언을 위해 static을 이용한다. (DATA 영역에 할당)
        // 읽기 전용으로 만들기 위해 본체 인스턴스는 private 처리해준다.
        private static SingletonEx _instance;

        // 인스턴스를 읽어오기 위한 프로퍼티 설정.
        public static SingletonEx instance {
            get {
                // 인스턴스가 비어있으면 하나 만들어준다.
                if (_instance == null) _instance = new SingletonEx();
                // 인스턴스 반환.
                return _instance;
            }
        }
    }

    // 델리게이트 선언. 파라미터로 사용하기 위해선 public 처리해 주어야한다.
    public delegate int DelEx(params int[] a);

    // 델리게이트 예시 클래스. 싱글톤을 이용해 만들어보았다.
    public class DelegateEx
    {
        private static DelegateEx _instance;

        public static DelegateEx instance
        {
            get {
                if (_instance == null) _instance = new DelegateEx();
                return _instance;
            }
        }

        // 델리게이트에 넣어줄 함수 1.
        public int Plus(params int[] a) {
            int sum = 0;
            foreach (var i in a) { sum += i; };
            Console.WriteLine("Plus에 들렀습니다 : {0}", sum);
            return sum;
        }

        // 델리게이트에 넣어줄 함수 2.
        public int Minus(params int[] a) {
            int sum = 0;
            foreach (var i in a) { sum -= i; };
            Console.WriteLine("Minus에 들렀습니다 : {0}", sum);
            return sum;
        }

        // 델리게이트 사용 함수.
        public void DelChain()
        {
            // 최초 인스턴스 생성 시 반드시 할당 해주어야 한다.
            DelEx del = new DelEx(Plus);
            // new를 생략하여 사용도 가능.
            del = Minus;

            // 연산자를 이용하여 델리게이트 내부에 더하거나 빼줄수 있음.
            del += Plus;
            del += delegate { Console.WriteLine("무명 메서드를 활용 : {0}", 777); return 15; };

            // WriteLine은 가장 끝의 인덱스에 있는 리턴 정보를 가져온다. 즉, Minus의 반환값이 아닌 Plus의 반환값만 가져온다.
            Console.WriteLine("가장 마지막 인덱스의 반환값입니다 : {0}", del(5, 5, 5));
            DelExample(del);
        }

        // 메서드의 파라미터로도 사용할 수 있다.
        public void DelExample(DelEx ex)
        {
            // WriteLine은 가장 마지막 메서드에 있는 리턴 정보를 가져온다. 즉, Minus의 반환값이 아닌 Plus의 반환값만 가져온다.
            Console.WriteLine("가장 마지막 메서드의 반환값입니다 : {0}", ex(5, 5, 5));
        }

    }

    public class EventEx
    {
        public delegate int ExDel(params int[] a);
        // event는 delegate와 보안 수준을 맞춰주어야 한다.
        public event ExDel exEvent;


        // 이벤트에 넣어줄 함수 1.
        public int Plus(params int[] a)
        {
            int sum = 0;
            foreach (var i in a) { sum += i; };
            Console.WriteLine("Plus에 들렀습니다 : {0}", sum);
            return sum;
        }

        // 이벤트에 넣어줄 함수 2.
        public int Minus(params int[] a)
        {
            int sum = 0;
            foreach (var i in a) { sum -= i; };
            Console.WriteLine("Minus에 들렀습니다 : {0}", sum);
            return sum;
        }

        public void UseEvent() {
            // 클래스 내부에서는 호출 및 할당 둘 다 가능.
            ExCallBack(exEvent);
            exEvent = Plus;
        }

        // 델리게이트형 파라미터로도 할용 가능.
        void ExCallBack(ExDel exDel) {
            exDel(5, 5, 5, 5, 5);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            //DelegateEx.instance.DelChain();

            EventEx eventEx = new EventEx();

            // 증감 연산자를 이용한 접근만 가능.
            eventEx.exEvent += eventEx.Plus;
            eventEx.exEvent += eventEx.Minus;

            // 클래스 외부에서 호출 및 할당을 할 수 없음.
            // eventEx.exEvent = eventEx.Plus;
            // eventEx.exEvent();

            byte a = 1;
            byte b = 2;

            byte c = (byte)(a + b);

            float s = 10;
            float q = 20;

            float t = s + q;

            eventEx.UseEvent();

        }
    }
}
