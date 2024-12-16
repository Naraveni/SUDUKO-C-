
/*
Harsha Vardhan Reddy Bana
Sreethi Sasikumar
*/

#include "tools.hpp"
#include "logger.hpp"
#include "square.hpp"
#include "state.hpp"
#include "game.hpp"
#include "fatalError.hpp"


void testState(State& state);
void testSquare(Square& square);
void testBoard(ifstream& inputfile);
void testCluster(ifstream& inputfile);
void testErrorHandlers(ifstream& inputfile);

int main(int argc, char *argv[]){
    try{
        banner();
        ifstream inputFile;
        try{
            inputFile.open(argv[1]);
            if (!inputFile.good()) throw InputFileNotFoundError();;
        }
        catch(InputFileNotFoundError e){
            e.print();
        }
        Game game(inputFile);
        game.run();
        // State state;
        // testState(state);

        // Square square;
        // testSquare(square);
        
        // testBoard(inputFile);
        //testErrorHandlers(inputFile);
        // testCluster(inputFile);
        
        bye();
        inputFile.close();
        return 0;
    }
    catch(exception e){
        fatal(e.what());
    }
}

// function for unit tests
// void testState(State& state){

//     Logger::getStream() << "STATE UNTI TESTING"<<'\n';

//     /*  Test1- Testing The parameter null contructor
//         Expected Result:
//         Scenario: Possibility having 0x3fe
//             Value: - 
//             Possibilities: 987654321
//         Scenario: Possibility having 0x3fe
//             Value: -
//             Possibilities: 9---54321
//      */
//     Logger::getStream() << "TEST1 - Actual Result"<<'\n';
//     state = State();
//     Logger::getStream() << (state)<<'\n';

//     /* Test2 - Testing constructor with parameter
//         Expected Result:
//         Scenario: Possibility having 0x3fe
//             Value: 3
//             Possibilities: --------- 
//         Scenario: Possibility having 0x3fe
//             Value: 3
//             Possibilities: --------- 
//     */
//     Logger::getStream() << "TEST2 - Actual Result"<<'\n';
//     state = State('3');
//     Logger::getStream() << (state)<<'\n';

//     /* Test3 - Testing Constructor  giving empty state value
//         Expected Result:
//         Scenario: Possibility having 0x3fe
//             Value: -
//             Possibilities:  987654321
//         Scenario: Possibility having 0x3fe
//             Value: -
//             Possibilities: 9---54321
        
//     */
//     Logger::getStream() << "TEST3 - Actual Result"<<'\n';
//     state = State('-');
//     Logger::getStream() << (state)<<'\n';

//     /* Test4 - Testing Mark Function in Fixed flase State by inserting 7
//       Expected Result:
//         Scenario: Possibility having 0x3fe
//             Value: 7 
//             Possibilities: ---------
//         Scenario: Possibility having 0x3fe
//             Console Message: Value 7 is not possible in this state
//             Value: -
//             Possibilities: 9---54321
//     */
//     Logger::getStream() << "TEST4 - Actual Result"<<'\n';
//     state.mark('7');
//     Logger::getStream() << (state)<<'\n';

//     /* Test5 - Testing Mark Function in Fixed true State by inserting 3 
//       Expected Result:
//         Scenario: Possibility having 0x3fe
//             Console Message: Position Is Fixed! Cannot Edit Fixed Positons
//             Value: 7
//             Possibilities: ---------
//         Scenario: Possibility having 0x3fe
//             Console Message: Position Is Fixed! Cannot Edit Fixed Positons
//             Value: 7
//             Possibilities: ---------
//     */
//     Logger::getStream() << "TEST5 - Actual Result"<<'\n';
//     state.mark('3');
//     Logger::getStream() << (state)<<'\n';

//     /* TEST6 - Testing the getValue Method 
//         Expected Result:
//             should return 7
//     */
//     Logger::getStream() << "TEST6 - Actual Result"<<'\n';
//     Logger::getStream() << state.getValue()<<'\n';
// }


// void testSquare(Square& square){

//     Logger::getStream() <<'\n'<< "SQUARE UNTI TESTING"<<'\n';

//     /*  
//     TEST 1 - Testing the default constructor
//     EXPECTED RESULT: Square[0,0] Value: -, Possibilities: 987654321
//     */
//     Logger::getStream() << "TEST1 - Actual Result"<<'\n';
//     square =  Square();
//     Logger::getStream() <<square<<'\n';

//     /*
//     TEST 2 - Testing the construtor with parameters value =9 , row = 0, column =1
//     EXPECTED RESULT: 
//     Square [0,1] created.
//     Square[0,1] Value: 9, Possibilities: ---------
//     */
//     Logger::getStream() << "TEST2- Actual Result"<<'\n';
//     square = Square('9',0,1);
//     Logger::getStream() <<square<<'\n';

//     /*
//     TEST 3 - Testing the construtor with parameters value =- , row = 9, column =9
//     EXPECTED RESULT: 
//     Square [9,9] created.
//     Square[9,9] Value: -, Possibilities: 987654321
//     */
//     Logger::getStream() << "TEST3 - Actual Result"<<'\n';
//     square = Square('-',9,9);
//     Logger::getStream() <<square<<'\n';

//     /*
//     TEST 3 - Testing the mark method on state object by passing '1' as parameter
//     EXPECTED RESULT: 
//     state before value update: Value: -, Possibilities: 987654321
//     state after value update: Value: 1, Possibilities: --------
//     Sqare[9,9] Value: 1, Possibilities: ---------

//     */
//     Logger::getStream() << "TEST4 - Actual Result"<<'\n';
//     square.mark('1');
//     Logger::getStream()<<square<<'\n';
// }

// void testBoard(ifstream& inputfile){

// //     /*
// //     TEST 1 - Input Puzzle with no valid game type
// //     EXPECTED RESULT: Should fatal error "FILE IS NOT PROCESSEBLE FOR THE GAME" onto console
// //     */
// //    Logger::getStream() << "TEST 1 - ACTUAL RESULT";
// //    Game game1(inputfile);


// //    /*
// //    TEST 2 - Input Puzzle with one less character in the first row of the suduko
// //    expected result: Should give fatal error "Invalid Data File" onto the console
// //    */
// //   Logger::getStream() << "TEST 2 - ACTUAL RESULT";
// //   Game game2(inputfile);

// //   /*
// //   TEST 3 - Input Puzzle with extra row for the suduko
// //   EXPECTED RESULT:  Should give fata Error "Invalid Data File" onto the console
// //   */
// //  Logger::getStream() << "TEST 3 - ACTUAL RESULT";
// //  Game game3(inputfile);

//   /*
//   TEST 4 - Input correct puzzle
//   EXPECTED RESULT:  Should print the board
//   */
//  Logger::getStream() << "TEST 4 - ACTUAL RESULT";
//  Game game4(inputfile);

//  /*
//     TEST 5 - Run method in game class should print the menu after with Quit option working as of now
//     EXPECTED RESULT: Should print the menu with Q quit being the only operation working
//  */
//   Logger::getStream()<< "TEST 5- ACTUAL RESULT";
//   game4.run();
// }

void testCluster(ifstream& inputFile){
    
     /*
    */
    Logger::getStream()<<'\n'<< "TEST 1 - TESTING BOARD CONSTRUCTION AND INTIAL SHOOP "<<'\n' << endl<<endl;
    /*
    TEST 1 - Testing whether possibilities of states of are updated after board construction
    */
    Logger::getStream() << endl<<endl<<"EXPECTED RESULT: The possibilities for each cell are updated as the board is constructed, and once a number is placed in a cell, it is removed from the list of possible values for all other cells in the same row, column, and 3x3 box, ensuring that the possibilities reflect valid options based on the current state of the board." << endl<<endl;

    Logger::getStream()<< "TEST 1- ACTUAL RESULT"<<endl<<endl;
    Game game(inputFile);


    /*
    */
    Logger::getStream()<<'\n'<< "TEST 2- TESTING SHOOP FUNCTION"<<'\n';
    /*
    TEST 2 - Testing the Shoop function by inserting "2" in the position (1,2) in the suduko
    */
    Logger::getStream() << "EXPECTED RESULT: The possibilities in row 1, column 2, and the 3x3 box containing cell (1,2) should be updated to exclude the value 2, ensuring that 2 is no longer considered a valid option for any other cells in the same row, column, or box." << endl<<endl;
    Logger::getStream()<<endl<<endl << endl<<"TEST 2- ACTUAL RESULT" << endl<<endl << endl<<endl;
    game.run();
    Logger::getStream() << "\n\n\nBoard After Updating State in (2,1) to 2\n\n\n";
    Logger::getStream() << *game.getBoard();
}

void testErrorHandlers(ifstream& inputfile){
        /*
        TEST1: Execute the executable file without giving file name in the command line arguments
        EXPECTED RESULT: should throw InputFileNotFound Error and print the proper message.
        */


       /*
       TEST2: Give a modified input puzzle file with not valid GameType
       EXPECTED RESULT: should throw GameTypeNotValid and print proper message to the output file
        */
    //    Logger::getStream() << "TEST2: ACTUAL RESULT\n";
    //    Game game(inputfile);


        /*
       TEST3: Give a modified input puzzle file with not valid character
       EXPECTED RESULT: should throw InvalidInputFile error and print proper message to output file
        */
    //    Logger::getStream() << "TEST3: ACTUAL RESULT\n";
    //    Game game(inputfile);


       /*
       TEST4: Try to Mark a position in the suduko which is already fixed
       EXPECTED RESULT: should throw StateNotEmpty error then print proper message to the output and should not interrupt execution
       NOTES: In the Game::run method, please update the indices in the mark function call to point to positions that are already fixed.
        */
    //    Logger::getStream() << "TEST4: ACTUAL RESULT\n";
    //    Game game(inputfile);
    //    game.run();


        /*
       TEST5: Try to Mark a position in the suduko with a value which has not possibility in that position
       EXPECTED RESULT: should throw valueNotPossible error then print proper message to the output and should not interrupt execution
       NOTES: In the Game::run method, please update the indices in the mark function call to point to positions that have no possibility of value you are trying to insert.
        */
       Logger::getStream() << "TEST5: ACTUAL RESULT\n";
       Game game(inputfile);
       game.run();

}


