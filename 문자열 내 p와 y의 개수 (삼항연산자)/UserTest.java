package com.ssafy.hw.step2;

public class UserTest {
	
	public static void main(String[] args) {
		User user1 = new User("이창민", 27);
		User user2 = new User("이창민이", 27);
		User user3 = new VipUser("류혜린", 24, "Gold", 500);
		User[] users = {user1, user2, user3};
		UserManager manager = new UserManager();
		
		manager.add(users);

		// 특정 이름 포함하는 유저 이름 출력
		System.out.print("특정 이름 포함하는 유저 이름 출력 : ");
		for (int i = 0; i < manager.searchByName("민이").length; ++i) {
			System.out.print(manager.searchByName("민이")[i].getName() + " ");
		}
		System.out.println();

		// 일반 유저 목록 출력
		System.out.print(manager.getUsers()[0].toString());
		for (int i = 0; i < manager.getUsers().length; ++i) {
			System.out.print(manager.getUsers()[i].getName() + " ");
		}
		System.out.println();

		// VIP 유저 목록 출력
		System.out.print(manager.getVipUsers()[0].toString());
		for (int i = 0; i < manager.getVipUsers().length; ++i) {
			System.out.print(manager.getVipUsers()[i].getName() + " ");
		}
		System.out.println();

		// 평균 나이 출력
		System.out.println("평균나이 : " + manager.getAgeAvg());
	}
}
