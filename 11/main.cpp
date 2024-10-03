#include "cipher.hpp"

int main(int argc, char *argv[]) {
    if(argc != 4) {
        cerr << "Incorrect parameters! Enter: <input_file> <output_file> <key>! \n" << endl;
        return 1;
    }

    string input_filename = argv[1];
    string output_filename = argv[2];
    int key = 0;
    try {
        key = stoi(argv[3], nullptr, 10); }
    catch(...) {
        clog<< "Error: Incorrect <key>!\n"; }
    try {
        input input(input_filename);
        output output(output_filename);

        input.set_key(key);
        output.set_key(key);
        output.set_key(0);

        while(!input.end_of_file()) {
            string line = input.get_input();
            output.pisz(line);
        }

    } catch (const ios_base::failure &e) {
        cerr << "Failure error: " << e.what() << endl;
        return 1;
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}