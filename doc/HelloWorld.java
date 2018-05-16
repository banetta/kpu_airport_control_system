package helloworld;

public class HelloWorld {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
//		출력
		System.out.println("HelloWorld!");
		System.out.println("Hello eclipse!");
		System.out.println(1+2);
		System.out.println("Hello"+"World"+"!!");
		
//		변수 이용 출력
		int a = 1;
		int b = 2;
		System.out.println("a is "+ a);
		System.out.println("b is "+ b);
		System.out.println("a + b = "+(a+b));
		
//		맞지않는 변수를 사용할 시에 error
//		java는 컨테이너 방식을 이용하기 때문
//		int a = 1.1;
//		System.out.println(a);
		
//		문자열
		String first="coding";
		System.out.println(first+" is Hard..");
		
		String second = " everybody";
		System.out.println(first+second);
		
//		boolean 비교 연산자
		
		System.out.println(1==1); // true
		System.out.println(1==2); // false
		System.out.println("one"=="one"); // true
		System.out.println(first==second); // false
		
		System.out.println(1!=1); // false
		System.out.println(1!=2); // true
		System.out.println("one"!="one"); // false
		System.out.println(first!=second); // true
		
		System.out.println(10>20); // 결과 : false
		System.out.println(10>2); // 결과 : true
		System.out.println(10>10); // 결과 : false
		 
		System.out.println(10<20); // 결과 : true
		System.out.println(10<2); // 결과 : false
		System.out.println(10<10); // 결과 : false

		System.out.println(10>=20); // 결과 : false
		System.out.println(10>=2); // 결과 : true
		System.out.println(10>=10); // 결과 : true
		 
		System.out.println(10<=20); // 결과 : true
		System.out.println(10<=2); // 결과 : false
		System.out.println(10<=10); // 결과 : true

//		문자열 비교
		String hello = "Hello world";
		String world = new String("Hello world");
		System.out.println(hello == world); // 결과 : false
		System.out.println(hello.equals(world)); // 결과 : true
		
//		==는 두개의 데이터 타입이 동일한 객체인지 알아내는 연산자이기 때문에 문자열에 사용하면 false를 출력한다
//		따라서 문자열을 비교하기 위해 .equals() 함수를 사용한다.
		
//		조건문 if
//		if(true){
//		    System.out.println(1);
//		}else if(true){
//		    System.out.println(2);
//		}else if(true){
//		    System.out.println(3);
//		}else{
//		    System.out.println(4);
//		}
		
//		switch문
//		
//		System.out.println("switch(1)");
//		switch(1){
//		case 1 :
//		    System.out.println("one");
//		case 2 :
//		    System.out.println("two");
//		case 3 :
//		    System.out.println("three");
//		}

		
	}

}
