
package Riya;

import java.util.Random;
import java.util.Scanner;

public class OptionMenu {
    private final Scanner s1;
    private final Bank bank;

    public OptionMenu() {
        s1 = new Scanner(System.in);
        bank = new Bank();
    }

    public void showOption() {
        System.out.println("------------Welcome to SDI ATM-----------------");
        while (true) {
            System.out.println("Press 1 to login.");
            System.out.println("Press 2 to create Account.");
            System.out.println("Press 3 exit.");
            System.out.print("Enter your option :- ");
            int choice = s1.nextInt();
            switch (choice) {
                case 1:
                    login();
                    break;
                case 2:
                    createAccount();
                    break;
                case 3:
                    System.exit(0);
                default:
                    System.out.println("Enter valid option !!");
            }
        }

    }

    private void createAccount() {
        System.out.print("Enter your name :- ");
        String name = s1.next();
        System.out.print("Enter mobile number :- ");
        String phoneNumber = s1.next();
        System.out.print("Enter 4 digit PIN :- ");
        int pin = s1.nextInt();
        String accountNumber = generateNumber(10);
        String cardNumber = generateNumber(16);
        ATMModel model = new ATMModel(
                name,
                phoneNumber,
                Long.parseLong(accountNumber),
                0.0,
                Long.parseLong(cardNumber),
                pin
        );
        bank.createAccount(model);
        System.out.println("Account is created !!!\nWelcome "+name +" to SDI back !!");
    }

    public static String generateNumber(int length) {
        Random random = new Random();

        StringBuilder cardNumber = new StringBuilder();
        for (int i = 0; i < length; i++) {
            cardNumber.append(random.nextInt(10));
        }

        return cardNumber.toString();
    }

    private void login() {
        System.out.print("Enter your mobile number :- ");
        String phoneNumber = s1.next();
        ATMModel account = bank.getAccount(phoneNumber);
        if (account == null) {
            System.out.println("Enter valid number !!");
            return;
        }
        loginMenu(account);
    }

    private void loginMenu(ATMModel account) {
        System.out.println("Login Successful\nWelcome " + account.getName());
        boolean isLogin = true;
        int choice;
        while (isLogin) {
            System.out.print("Press 1 to see account details.\n" +
                    "Press 2 to deposit.\n" +
                    "Press 3 to credit money.\n" +
                    "Press 4 to change pin.\n" +
                    "Press 5 to change MobileNumber.\n" +
                    "Press 6 to Logout\n"+
                    "Enter your choice :- "
            );
            choice = s1.nextInt();
            switch (choice){
                case 1: printDetails(account);
                break;
                case 2:{
                    System.out.print("Enter money to deposit :- ");
                    double money = s1.nextDouble();
                    int state = bank.updateBalance(
                            account.getPhoneNumber(),
                            money,
                            false
                    );
                    if(state == -1)
                        System.out.println("Can't able to update details right now !!");
                    else
                        System.out.println("Updated Successfully");
                }
                break;
                case 3: {
                    System.out.print("\nEnter money to credit :- ");
                    double money = s1.nextDouble();
                    int state = bank.updateBalance(
                            account.getPhoneNumber(),
                            money,
                            true
                    );
                    if(state == -1)
                        System.out.println("Can't able to update details right now !!");
                    else
                        System.out.println("Updated Successfully");
                }
                break;
                case 4 : {
                    System.out.print("\nEnter new PIN :- ");
                    int pin = s1.nextInt();
                    int state = bank.updatePIN(
                            account.getPhoneNumber(),
                            pin
                    );
                    if(state == -1)
                        System.out.println("Can't able to update details right now !!");
                    else
                        System.out.println("Updated Successfully");
                }
                break;
                case 5 : {
                    System.out.print("\nEnter your mobile number :- ");
                    String number = s1.next();
                    int state = bank.updatePhoneNumber(
                            account.getPhoneNumber(),
                           number
                    );
                    if(state == -1)
                        System.out.println("Can't able to update details right now !!");
                    else
                        System.out.println("Updated Successfully");
                }
                break;
                case 6 : {
                    isLogin = false;
                }
                break;
                default:
                    System.out.println("Enter valid option !!");
            }
        }
    }

    private void printDetails(ATMModel model) {
        System.out.println("--------------About Details--------------------\n" +
                "Name :- " + model.getName() + "\n" +
                "Account Number :- " + model.getAccountNumber() + "\n" +
                "Phone Number :- " + model.getPhoneNumber() + "\n" +
                "Card Number :- " + model.getCardNumber() + "\n" +
                "Back Balance :- " + model.getBalance()
        );
    }
}