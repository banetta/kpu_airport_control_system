package helloworld;

public class HelloWorld {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
//		���
		System.out.println("HelloWorld!");
		System.out.println("Hello eclipse!");
		System.out.println(1+2);
		System.out.println("Hello"+"World"+"!!");
		
//		���� �̿� ���
		int a = 1;
		int b = 2;
		System.out.println("a is "+ a);
		System.out.println("b is "+ b);
		System.out.println("a + b = "+(a+b));
		
//		�����ʴ� ������ ����� �ÿ� error
//		java�� �����̳� ����� �̿��ϱ� ����
//		int a = 1.1;
//		System.out.println(a);
		
//		���ڿ�
		String first="coding";
		System.out.println(first+" is Hard..");
		
		String second = " everybody";
		System.out.println(first+second);
		
//		boolean �� ������
		
		System.out.println(1==1); // true
		System.out.println(1==2); // false
		System.out.println("one"=="one"); // true
		System.out.println(first==second); // false
		
		System.out.println(1!=1); // false
		System.out.println(1!=2); // true
		System.out.println("one"!="one"); // false
		System.out.println(first!=second); // true
		
		System.out.println(10>20); // ��� : false
		System.out.println(10>2); // ��� : true
		System.out.println(10>10); // ��� : false
		 
		System.out.println(10<20); // ��� : true
		System.out.println(10<2); // ��� : false
		System.out.println(10<10); // ��� : false

		System.out.println(10>=20); // ��� : false
		System.out.println(10>=2); // ��� : true
		System.out.println(10>=10); // ��� : true
		 
		System.out.println(10<=20); // ��� : true
		System.out.println(10<=2); // ��� : false
		System.out.println(10<=10); // ��� : true

//		���ڿ� ��
		String hello = "Hello world";
		String world = new String("Hello world");
		System.out.println(hello == world); // ��� : false
		System.out.println(hello.equals(world)); // ��� : true
		
//		==�� �ΰ��� ������ Ÿ���� ������ ��ü���� �˾Ƴ��� �������̱� ������ ���ڿ��� ����ϸ� false�� ����Ѵ�
//		���� ���ڿ��� ���ϱ� ���� .equals() �Լ��� ����Ѵ�.
		
//		���ǹ� if
//		if(true){
//		    System.out.println(1);
//		}else if(true){
//		    System.out.println(2);
//		}else if(true){
//		    System.out.println(3);
//		}else{
//		    System.out.println(4);
//		}
		
//		switch��
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
