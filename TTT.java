import java.util.*;

public class TTT {

    static ArrayList<Integer> PlayerPostitions = new ArrayList<>();
    static ArrayList<Integer> CpuPostitions = new ArrayList<>();


    public static void main(String arg[]) {

        char[][] gameboard = {{' ', '|', ' ', '|', ' '},
                {'-', '+', '-', '+', '-'},
                {' ', '|', ' ', '|', ' '},
                {'-', '+', '-', '+', '-'},
                {' ', '|', ' ', '|', ' '}};

        printgameboard(gameboard);
        System.out.println("");



        while (true) {

            Scanner scan = new Scanner(System.in);
            Random rand = new Random();
            System.out.println("X move: ");


            //int playerPosition = scan.nextInt();
            int playerPosition = rand.nextInt(9) + 1;
            while(PlayerPostitions.contains(playerPosition) || CpuPostitions.contains(playerPosition)){
                //System.out.println("not valid positions! try again! ");
                //playerPosition = scan.nextInt();
                playerPosition = rand.nextInt(9) + 1;
            }

            MakeMove(gameboard, playerPosition, "player");
            printgameboard(gameboard);
            System.out.println(" ");
            String result = checkwin();
            if(result.length() > 0) {
                System.out.println(result);
                break;
            }

            System.out.println("O Move: ");
            int cpuPosition = rand.nextInt(9) + 1;

            while(PlayerPostitions.contains(cpuPosition) || CpuPostitions.contains(cpuPosition)){
                //System.out.println("not valid positions! try again! ");
                cpuPosition = rand.nextInt(9) +1;
            }
            MakeMove(gameboard, cpuPosition, "cpu");

            printgameboard(gameboard);
            System.out.println(" ");
            result = checkwin();
            if(result.length() > 0) {
                System.out.println(result);
                break;
            }

            //printgameboard(gameboard);
        }
        printgameboard(gameboard);
    }
    public static void printgameboard(char[][] gameboard){
        for (char[] row : gameboard) {
            for (char c : row) {
                System.out.print(c);
            }
            System.out.println();
        }
    }

    public static void MakeMove(char[][] gameboard, int position, String user){
        char symbol = ' ';

        if(user.equals("player")){
            symbol = 'X';
            PlayerPostitions.add(position);
        }else if(user.equals("cpu")){
            symbol = 'O';
            CpuPostitions.add(position);
        }

        switch(position){
            case 1:
                gameboard[0][0] = symbol;
                break;
            case 2:
                gameboard[0][2] = symbol;
                break;
            case 3:
                gameboard[0][4] = symbol;
                break;
            case 4:
                gameboard[2][0] = symbol;
                break;
            case 5:
                gameboard[2][2] = symbol;
                break;
            case 6:
                gameboard[2][4] = symbol;
                break;
            case 7:
                gameboard[4][0] = symbol;
                break;
            case 8:
                gameboard[4][2] = symbol;
                break;
            case 9:
                gameboard[4][4] = symbol;
                break;
            default:
                break;

        }
    }

    public static String checkwin(){

        List topRow = Arrays.asList(1,2,3);
        List midRow = Arrays.asList(4,5,6);
        List botRow = Arrays.asList(7,8,9);

        List leftcol = Arrays.asList(1,4,7);
        List midcol = Arrays.asList(2,5,8);
        List rightcol = Arrays.asList(3,6,9);

        List cross1 = Arrays.asList(1,5,9);
        List cross2 = Arrays.asList(7,5,3);

        List<List> winconditions = new ArrayList<>();
        winconditions.add(topRow);
        winconditions.add(midRow);
        winconditions.add(botRow);
        winconditions.add(leftcol);
        winconditions.add(midcol);
        winconditions.add(rightcol);
        winconditions.add(cross1);
        winconditions.add(cross2);

        for(List l : winconditions){

            if(PlayerPostitions.containsAll(l)){
                return "X WIN";
            }else if(CpuPostitions.containsAll(l)){
                return "O WIN";
            }else if (PlayerPostitions.size() + CpuPostitions.size() == 9){
                return "GAME IS TIE!";
            }

        }



        return "";
    }



}//end of class
