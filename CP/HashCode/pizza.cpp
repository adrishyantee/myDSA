#include <bits/stdc++.h>

using namespace std;

class Cell {
    int x;
    int y;
    char ingredient;
    bool cutOut = false;
};


class Pizza { 
    int rows;
    int cols;
    int minIngredientEachPerSlice;
    int maxCellsPerSlice;
    unordered_map<string, Cell> cells;
    int rowLength;
    int colLength;
    
    string getCellHashKey (int x, int y) {
        return string.format("%0" + rowLength + "d", x) +    string.format("%0" + colLength + "d", y);
    }
};

class PizzaCutter {
   
    Pizza pizza;
    ArrayList<Slice> cutSlices = new ArrayList<>();
  
    PizzaCutter (Pizza pizza) {
        this.pizza = pizza;
    }
};


public class Slice {
    int startX;
    int endX;
    int startY;
    int endY;
};

public class Simulator {
   private String fileName;
   private Pizza pizza;
   private PizzaCutter pizzaCutter;
  
   public Simulator (String fileName) {
      this.fileName = fileName;
   }
  
   public void parseInput () {
   
   }
  
   public void simulate() {
     
   }
  
   public void printOutput () {
     
   }
}

public static void main(String[] args) {
  
    String[] inputs = {"a_example", "b_small", "c_medium", "d_big"};
    for (String in: inputs) {
        String fileName = "path/to/datasets/" + in;
        Simulator simulator = new Simulator(fileName);
        simulator.parseInput();
        simulator.simulate();
        simulator.printOutput();
    }
 }