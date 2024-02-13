package Riya;


import java.util.ArrayList;
import java.util.List;

public class Bank {
    private final List<ATMModel> account = new ArrayList<>() {{
        add(new ATMModel("John Doe", "1234567890", 123456789, 1000, 987654321, 1234));
        add(new ATMModel("Jane Doe", "4567890123", 987654321, 2000, 123456789, 4321));
        add(new ATMModel("Peter Parker", "7890123456", 345678901, 3000, 987654321, 1234));
        add(new ATMModel("Mary Jane Watson", "0123456789", 678901234, 4000, 345678901, 4321));
        add(new ATMModel("Bruce Wayne", "6268993859", 567890123, 5000, 678901234, 1234));
    }};



    public void createAccount(ATMModel model) {
        account.add(model);
    }

    public ATMModel getAccount(String phoneNumber) {
        return account.stream()
                .filter(v -> v.getPhoneNumber().equals(phoneNumber))
                .findFirst().orElse(null);
    }
    public int updatePhoneNumber(String phoneNumber,String newPhoneNumber){
        ATMModel model = account.stream()
                .filter(v -> v.getPhoneNumber().equals(phoneNumber))
                .findFirst().orElse(null);
        if(model ==null){
            System.out.println("No account is linked to this phone number!!");
            return  -1;
        }
        model.setPhoneNumber(newPhoneNumber);
        return 1;
    }
    public int updatePIN(String phoneNumber,int pin){
        ATMModel model = account.stream()
                .filter(v -> v.getPhoneNumber().equals(phoneNumber))
                .findFirst().orElse(null);
        if(model ==null){
            System.out.println("No account is linked to this phone number!!");
            return  -1;
        }
        model.setPin(pin);
        return 1;
    }
    
    public int updateBalance(String phoneNumber,double balance, boolean isCredited){
        ATMModel model = account.stream()
                .filter(v -> v.getPhoneNumber().equals(phoneNumber))
                .findFirst().orElse(null);
        if(model ==null){
            System.out.println("No account is linked to this phone number!!");
            return  -1;
        }
        if(isCredited)
            model.setBalance(model.getBalance()+balance);
        else
            model.setBalance(model.getBalance()-balance);
        return 1;
    }
}