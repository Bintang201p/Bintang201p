public class Main {
    
    public static String[] model = new String[10];
    public static java.util.Scanner scanner = new java.util.Scanner(System.in);
    
    public static void main(String[] args) {
        viewTodoList();
    }    
    
    // Show Todo List
    public static void showTodoList(){
        System.out.println("\033[36m↓↓ TODO LIST ↓↓\033[0m");
        for(int i = 0; i < model.length; i++){
            var todo = model[i];
            var no = i + 1;
            if(model[i] != null){
                System.out.println("\033[32m" + no + ". " + todo + "\033[0m");
            }
        }
        System.out.println("\033[36m↑↑ TODO LIST ↑↑\033[0m");
    }
    
    // Add New Element to Todo List
    public static void addTodoList(String todo){
        boolean isFull = true;
        for(int i = 0; i < model.length; i++){
            if(model[i] == null){
                isFull = false;
                break;
            }
        }
        if(isFull){
            var temp = model;
            model = new String[model.length * 2];
            for(int i = 0; i < temp.length; i++){
                model[i] = temp[i];
            }
        }
        for(int i = 0; i < model.length; i++){
            if(model[i] == null){
                model[i] = todo;
                break;
            }
        }
    }
    
    // Remove Element in Todo List
    public static boolean removeTodoList(Integer number){
        if((number - 1) >= model.length){
            return false;
        } else if(model[number - 1] == null){
            return false;
        } else {
            for(int i = (number - 1); i < model.length; i ++){
                if(i == (model.length - 1)){
                    model[i] = null;
                } else {
                    model[i] = model[i + 1];
                }
            }
            return true;
        }
    }
    
    // Input User
    public static String input(String info){
        System.out.print(info + ": ");
        String data = scanner.nextLine();
        return data;
    }
    
    // Show The View Todo List
    public static void viewTodoList(){
        while(true){
            showTodoList();
            System.out.println("Menu");
            System.out.println("1. Add");
            System.out.println("2. Remove");
            System.out.println("x. exit");
        
            String input = input("Chose");
            
            if(input.equals("1")){
                viewAddTodoList();
            } else if(input.equals("2")){
                viewRemoveTodoList();
            } else if(input.equals("x")){
                break;
            } else{
                System.out.println("Pleass chose the correct option!");
            }
        }
    }
    
    // Show The View To Add Todo List
    public static void viewAddTodoList(){
        String todo = input("Add todo (x to cancel)");
        
        if(todo.equals("x")){
            //exit
        } else {
            addTodoList(todo);
        }
    }
    
    // Show The View To Remove Todo List
    public static void viewRemoveTodoList(){
        var number = input("Remove todo (x to cancel)");
        if(number.equals("x")){
            //exit
        } else {
            boolean success = removeTodoList(Integer.valueOf(number));
            if(!success){
                System.out.println("Removing failed: " + number);
            }
        }
    }
}
