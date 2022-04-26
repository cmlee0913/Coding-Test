//using System;
//using System.Collections;

//namespace Intro_Ex1
//{
//    class Example
//    {
//        public void UseParams(params int[] list) {
//            foreach (int param in list) {
//                Console.WriteLine(param);
//            }
//            Console.WriteLine();
//        }

//        public void UseRefs(ref int[] list)
//        {
//            list = new int[] { 3, 6, 9, 12, 15 };
//        }

//        public void NonUseRefs(int[] list)
//        {
//            list = new int[] { 3, 6, 9, 12, 15 };
//        }

//        // 함수 내에서 매개 변수를 할당하지 않았으니 에러
//        //public void UseOut1(out int[] list)
//        //{
            
//        //}

//        // 반드시 함수 내에서 매개 변수를 할당해주어야 한다.
//        public void UseOut2(out int[] list)
//        {
//            list = new int[] { 4, 8, 12, 16, 20 };
//        }

//        public void UseIn(in int[] list)
//        {
//            // 읽기 전용이므로 할당 및 초기화 불가능
//            //list = new int[] { 4, 8, 12, 16, 20 };

//            // 읽기만 가능하나 반드시 해야할 필요는 없다.
//            int[] s = list;
//        }
       
//    }

//    class Program
//    {

//        static void Main(string[] args)
//        {
//            Example example = new Example();
//            int[] array1 = { 1, 3, 5, 7, 9 };

//            object a = 0;

//            // 쉼표로 구분된 인수 목록 사용
//            example.UseParams(array1);

//            // 지정된 형식의 인수 배열을 사용
//            example.UseParams(2, 4, 6, 8, 10);

//            // 가변 길이를 사용 가능하기에 인수가 없어도 사용 가능
//            example.UseParams();

//            // 키워드 미사용 시
//            example.NonUseRefs(array1);
//            example.UseParams(array1);

//            // 키워드 사용 시 (꼭 인수 앞에 키워드를 붙여주어야 한다.)
//            example.UseRefs(ref array1);
//            example.UseParams(array1);

//            // 반드시 초기화 할 필요는 없다.
//            int[] array2;

//            //example.UseOut1(out array2);
//            example.UseOut2(out array2);

//            example.UseIn(in array1);
//            example.UseIn(array1);
//        }
//    }
//}