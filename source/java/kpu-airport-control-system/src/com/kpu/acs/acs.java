package com.kpu.acs;
import java.util.*;
import java.time.*;

class Ticket{
	private String ticket_seat;
	private int entryday[]; // �Ա���
	private int leaveday[]; // �ⱹ��

	Ticket(String userticketseat, int userentryday[], int userleaveday[]) {
	    ticket_seat = userticketseat;
	    for (int i = 0; i < 3; i++) {
	    entryday[i] = userentryday[i];
	    leaveday[i] = userleaveday[i];
	    }
	}
}

class User{
    private int passnum;
    private String name;
    private int age;
    private String region;
    private Ticket myTicket;

    User() {}
    User(int userpassnum, String username, int userage, String userregion, String userticketseat,int userentryday, int userleaveday) {
       passnum = userpassnum;
       name = username;
       age = userage;
       region = userregion;
       //myTicket userticketseat, userentryday, userleaveday
    }
    int blacklist() {
       return passnum;
    }
    void showyou() {
       System.out.printf("Passnumber : %d Name : %s \n", passnum, name);
    }
}

class Leaveitem{
   private int isBanitem;
   Leaveitem(){}
   Leaveitem(int l)
   {isBanitem=l;}
   void isBanitem_init()
   { Random random =new Random();
      isBanitem =random.nextInt(20); }
   int sendban()
   {return isBanitem;}
}

class Leavelist extends User{
	Leavelist(){}
	
}

class RFID{
	private int price;
	private int[] buyday;
	RFID(){}
	void RFID_init(int ipay, int[] ibuyday) {
		price = ipay;
		buyday = ibuyday;
	}
	int RFID_buypick(int[] entryday, int[] leaveday) {
		LocalDate entryDate = LocalDate.of(entryday[0],entryday[1],entryday[2]);
		LocalDate leaveDate = LocalDate.of(leaveday[0], leaveday[1], leaveday[2]);
		LocalDate buyDate = LocalDate.of(buyday[0], buyday[1], buyday[2]);
		
		if (buyDate.isAfter(entryDate) == buyDate.isBefore(leaveDate)) {
			
			return price;
		}
		else {
			return 0;
		}

	}
}

class Entryitem{
	private RFID rfid;
	Entryitem() {}
		void item_init() 
		{
			Random random=new Random();
			int pay = random.nextInt(10000)*100;
			int[] buyday= {2013+random.nextInt(5),1+random.nextInt(12),1+random.nextInt(27)};
			rfid.RFID_init(pay, buyday);
		}
		int passing_price(int []entryday, int []leaveday)
		{
			return rfid.RFID_buypick(entryday, leaveday);
		}
}

class Entrylist extends User{
	
}

class Flightschedule{
	  private String airline;
	  private String destination;
	  private int seat[];
	  private int hour2;
	  private String shit2;
	  private int min2;
	  Flightschedule(){}
	  Flightschedule(String fairline, String fdestination, int fseat[], int fhour, String fshit, int fmin) {
	     airline = fairline;
	     destination = fdestination;
	     hour2 = fhour;
	     shit2 = fshit;
	     min2 = fmin;
	     for (int i = 0; i < 3; i++) {
	        seat[i] = fseat[i];
	     }
	  }
	  
	  void showthat() {
	     if (min2 == 0)
	        System.out.printf(airline, "\t", destination, "\t", seat[0], "\t", seat[1], "\t", seat[2], "\t", hour2, shit2, "0", min2);
	     else
	        System.out.printf("%s\t %s\t %d\t %d\t %d\t %d%s%d", airline, destination, seat[0], seat[1], seat[2], hour2, shit2, min2);
	   }

	   void takeoff_check(Controltower ct) {// �������� �� �¼� üũ �Լ�
	      int set, set2;
	      int i = 0;

	      while (i == 0) {
	         set = ct.weathercenter_check(); // ���û
	         set2 = ct.runway_check(); // Ȱ�ַ�

	         if (min2 >= 60) {
	            min2 -= 60;
	            hour2 += 1;
	         }
	         showthat();
	         if (set > 3 && set2 > 0) {
	            System.out.println("\nDelay in Airplain, Reason : Bad weather. \n\n");
	            min2 += 30;
	         } else if (set2 == 0 && set < 4) {
	            System.out.println("\nDelay in Airplain, Reason : Runway exceeded. \n\n");
	            min2 += 10;
	         } else if (set > 3 && set2 == 0) {
	            System.out.println("\nDelay in Airplain, Reason : Bad weather and Runway exceeded.  \n\n");
	            min2 += 40;
	         } else {
	            System.out.println("\nComplete.\n");
	            i = 1;
	         }
	      }
	   }

}

class Controltower{
	 private int runway;
	 private int weather;

	 Controltower() {}
	 int weathercenter_check() {
		 Random rands = new Random();
	     weather = 1 + rands.nextInt(5); // 1~5 �������� �ο�
	     return weather;
	 }

	 int runway_check() {
	     Random rands2 = new Random();
	     runway = rands2.nextInt(4); // 0~4 �������� �ο� , 0�Ͻ� ���� Ȱ�ַ� 0
	     return runway;
	 }
}

class Blacklist{
	  private int reason;
	  Blacklist() {}

	  int reason_print(int upass) {
	     switch (upass % 100) {
	     case 0:
	        System.out.println("Reason : �ҹ�ü�� ��� ����");
	        reason = 1;
	        return reason;
	     case 1:
	        System.out.println("Reason : ���Ա� ��� ����");
	        reason = 1;
	        return reason;
	     case 2:
	        System.out.println("Reason : �׷�����Ʈ �з�");
	        reason = 1;
	        return reason;
	     case 3:
	        System.out.println("Reason : �������� ������");
	        reason = 1;
	        return reason;
	     default:
	        System.out.println("������Ʈ �ش���� ����");
	        reason = 0;
	        return reason;
	     }
	  }
}

class Tariff{
	private int pay_amount;
	private int tariff_amount;
	
	void getRFID_amount(Entrylist elist) {
		pay_amount = elist.passing_price();
	}
	void calcTariff(Entrylist elist) {
		getRFID_amount(elist);
		if (pay_amount >= 200000) {
			tariff_amount = (int)(pay_amount * 0.2);
		}
		else {
			tariff_amount = 0;
		}
	}
	
	void Tairff_print(Entrylist elist) {
		
		calcTariff(elist);
		System.out.println("�� �̿��ڿ��� �ΰ��� �� ������ "+tariff_amount+"�� �Դϴ�.");
	}
}

class main_func{
	
}

public class acs {
	public static int main(String[] args) {
	      // TODO Auto-generated method stub
	      // Airport Control System Main Function
	      // coding by Banetta Han Sang Kim

	         Flightschedule[] fs;
	         Controltower ct;
	         Entrylist[] elist;
	         Leavelist[] llist;
	         Entrylist[] banlist;
	         Scanner sc = new Scanner(System.in);
	         

	         System.out.println("===   Airport Control System [ACS]   ===\n");
	         while (true)   //   Menu ����
	         {
	            // Menu ���
	            System.out.println("=== Menu ===\n");
	            System.out.println("i : File Input\n");
	            System.out.println("e : Entry Process\n");   //   �Ա� ����
	            System.out.println("l : Leave Process\n");   //   �ⱹ ����
	            System.out.println("t : Today Airplain list\n");   // ���� ������ ���
	            System.out.println("a : Airplain Access Management\n");   // �װ��� ������ ����
	            System.out.println("o : OverEntryUser Check\n");   //   �ҹ� ü���� üũ
	            System.out.println("q : Quit Program\n");   //   ���α׷� ����
	            System.out.println("[ACS]:# \n");

	            
	            switch (sc.nextLine().charAt(0))   //   menu switch�� : getchar()�� �̿�, ���ڸ� �޾Ƽ� ����
	            {
	            case 'i':   //   �̿��� ���� ���� �Է� �޴�
	               while (sc.nextLine().charAt(0) != '\n');   //   getchar()���� ���ۿ� �Է°��� ���Ƽ� ���߽����� �� �� �ֱ� ������ ���۸� ���� �۾��� �Ѵ�.
	               System.out.println("���� �װ��� ������ ������ �ҷ��ɴϴ�");
	               createFlightSchedule(fs);
	               System.out.println("���� �װ��� ������ ���� �ҷ����� �Ϸ�");
	               System.out.println("�̿��� ������ �ҷ��ɴϴ�");
	               createUser(elist);   
	               createUser(llist);   
	               createban(banlist);   
	               System.out.println("�̿��� ���� �ҷ����� �Ϸ�");
	               break;
	            case 'e':   //   �Ա� ���� �޴�
	               while (sc.nextLine().charAt(0) != '\n');   //   ���۸� ���� �۾�.
	               leaveprocess(elist);
	               break;
	            case 'l':   //   �ⱹ ���� �޴�
	               while (sc.nextLine().charAt(0) != '\n');   //   ���۸� ���� �۾�.
	               leaveprocess(llist);
	               break;
	            case 't':   //   ���� ������ ���
	               while (c != '\n');   //   ���۸� ���� �۾�.
	               Airplainlist(fs);
	               break;
	            case 'a':   //   ����� ������ ���� �޴�
	               while (sc.nextLine().charAt(0) != '\n');   //   ���۸� ���� �۾�.
	               Airlinemanagement(fs, ct);
	               break;
	            case 'o':   //   �ҹ� ü���� üũ �޴�
	               while (sc.nextLine().charAt(0) != '\n');   //   ���۸� ���� �۾�.
	               Illegal_resident(banlist);
	               break;
	            case 'q':   //   ���α׷� ���� �޴�
	               while (sc.nextLine().charAt(0) != '\n');   //   ���۸� ���� �۾�.
	               System.out.println("\n\n");
	               System.out.println("end of program\n");
	               return 0;   //   ���α׷� ����
	            default:   //   error ��� ��� (�޴� �߸� �Է½�)
	               while (sc.nextLine().charAt(0) != '\n');   //   ���۸� ���� �۾�.
	               System.out.println("\nerror!! worng char\n");
	               break;
	            }
	         }
	      }

}