#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>


        /*
            Submitted By
            Md. Jumar Alam              1610512042
            A. B. M. Tanjeeb Alam       1510338642
            Md. Jahid Khandaker         1611131042
            Muhtasim Riffat             1511043042
        */



/**
    *                                    #####Instruction Manual#####
    *           instruction that can be translated are:
    *           add, addi, sub, sll, and, nand, lw, sw, beq, slt, jmp, dsp, inp, otp.
    *
    *           Registers are: $sp, $s1 to $s15.
    *
    *           For lw and sw the ofset value can be used between 0 to 15.
    *
    *           For beq and jmp the lebel value or jump value can be between -8 to 7
    *
    *   ######   Beyond these limitations, this assembler will handle the error and generate "Invalid" message. ######
    *
*/
using namespace std;


string convert_Bin_to_Hex(string bin)
{
    string hex;

    if(bin == "0000")
        hex = "0";
    else if(bin == "0001")
        hex = "1";
    else if(bin == "0010")
        hex = "2";
    else if(bin == "0011")
        hex = "3";
    else if(bin == "0100")
        hex = "4";
    else if(bin == "0101")
        hex = "5";
    else if(bin == "0110")
        hex = "6";
    else if(bin == "0111")
        hex = "7";
    else if(bin == "1000")
        hex = "8";
    else if(bin == "1001")
        hex = "9";
    else if(bin == "1010")
        hex = "a";
    else if(bin == "1011")
        hex = "b";
    else if(bin == "1100")
        hex = "c";
    else if(bin == "1101")
        hex = "d";
    else if(bin == "1110")
        hex = "e";
    else if(bin == "1111")
        hex = "f";


    return hex;
}
string check_instruction(string inst)
{
    string conv_inst;
    if(inst == "add")
        conv_inst = "0000";

    else if(inst == "addi")
        conv_inst = "0001";

    else if(inst == "sub")
        conv_inst = "0010";

    else if(inst == "sll")
        conv_inst = "0011";

    else if(inst == "and")
        conv_inst = "0100";

    else if(inst == "nand")
        conv_inst = "0101";

    else if(inst == "lw")
        conv_inst = "0110";

    else if(inst == "sw")
        conv_inst = "0111";

    else if(inst == "dsp")
        conv_inst = "1000";

    else if(inst == "inp")
        conv_inst = "1001";

    else if(inst == "otp")
        conv_inst = "1010";

    else if(inst == "beq")
        conv_inst = "1011";

    else if(inst == "slt")
        conv_inst = "1100";

    else if(inst == "jmp")
        conv_inst = "1101";

    else
        conv_inst = "invalid instruction";

    return conv_inst;
}

string check_register(string reg)
{
    string conv_reg;

    if(reg == "$sp")
        conv_reg = "0000";

    else if(reg == "$s1")
        conv_reg = "0001";

    else if(reg == "$s2")
        conv_reg = "0010";

    else if(reg == "$s3")
        conv_reg = "0011";

    else if(reg == "$s4")
        conv_reg = "0100";

    else if(reg == "$s5")
        conv_reg = "0101";

    else if(reg == "$s6")
        conv_reg = "0110";

    else if(reg == "$s7")
        conv_reg = "0111";

    else if(reg == "$s8")
        conv_reg = "1000";

    else if(reg == "$s9")
        conv_reg = "1001";

    else if(reg == "$s10")
        conv_reg = "1010";

    else if(reg == "$s11")
        conv_reg = "1011";

    else if(reg == "$s12")
        conv_reg = "1100";

    else if(reg == "$s13")
        conv_reg = "1101";

    else if(reg == "$s14")
        conv_reg = "1110";

    else if(reg == "$s15")
        conv_reg = "1111";

    else
        conv_reg = "invalid register";

        return conv_reg;
}

string decimal_to_binary(int n){
    if (n<0){                   // check if negative and alter the number
        n = 16 + n;
    }
    string ext = "";
    string result = "";
    while(n > 0){
        result = (n%2==0 ? "0" : "1")  + result;    //string(1, (char) (n%2 + 48))
        n = n/2;
    }
    for(int i = 0; i< 4-result.size(); i++ )
    {
        ext = "0" + ext;
    }
    result = ext + result;
    return result;
}


int main()
{
    string con_ins, con_rs, con_rd, con_im;
    ifstream inFile;
    inFile.open("inputs");
    ofstream outFile;
    outFile.open("outputs");

    if(inFile.fail())
    {
        cerr << "Error occured" << endl;
        cerr << "No input file found" << endl;
        exit(1);
    }
    int i = 0;
    string ins, rd, rs, im, out;
    while(inFile>>ins)
    {
        transform(ins.begin(), ins.end(), ins.begin(), ::tolower);
        if(ins == "add" || ins == "sub" || ins == "and" || ins == "nand" || ins == "slt")
        {

            inFile >> rd >> rs;


            con_ins = check_instruction(ins);
            con_rd = check_register(rd);
            con_rs = check_register(rs);

            if(con_rd == "invalid register" || con_rs == "invalid register")
            {
                outFile << "invalid register"<< endl;
                cout << "invalid register" << endl;
                continue;
            }

            else
            {

                out = con_ins + con_rd + con_rs;
                cout << ins << endl;
                cout << out << endl;

                out = convert_Bin_to_Hex(con_ins) + convert_Bin_to_Hex(con_rd) + convert_Bin_to_Hex(con_rs);

                cout << out << endl;
                outFile<< out << endl;
            }



        }

        else if(ins == "addi" || ins == "sll" || ins == "lw" || ins == "sw" || ins == "beq")
        {
            inFile >> rd >> im;

            if(std::stoi(im)<0)
            {
                outFile << "immediate value can't be negative"<< endl;
                cout<< "immediate value can't be negative" << endl;
            }


            else if(stoi(im)>16)
            {
                outFile << "immediate value out of bound"<< endl;
                cout << "immediate value out of bound" << endl;
            }


            else
            {
                con_ins = check_instruction(ins);
                con_rd = check_register(rd);
                con_im = decimal_to_binary(stoi(im));

                if(con_rd == "invalid register")
                {
                    outFile << "invalid register"<< endl;
                    cout << "invalid register" << endl;
                    continue;
                }
                else
                {
                    out = con_ins + con_rd + con_im;

                    cout << ins << endl;
                    cout << out << endl;

                    out = convert_Bin_to_Hex(con_ins) + convert_Bin_to_Hex(con_rd) + convert_Bin_to_Hex(con_im);

                    cout << out << endl;
                    outFile<< out << endl;
                }

            }

        }
        else if(ins == "jmp")
        {
            inFile>> im;

            if(stoi(im)>8 || stoi(im)<-7)
            {
                 outFile << "immediate value is out of bound"<< endl;
                 cout<< "immediate value is out of bound" << endl;
            }

            else
            {
                out = con_ins + "0000" + con_im;

                cout << ins << endl;
                cout << out << endl;

                out = convert_Bin_to_Hex(con_ins) + "0" + convert_Bin_to_Hex(con_im);

                cout << out << endl;
                outFile<< out << endl;
            }
        }

        else if(ins == "inp" || ins == "otp")
        {
            inFile >> rd;

            con_ins = check_instruction(ins);
            con_rd = check_register(rd);
            if(con_rd == "invalid register")
            {
                    outFile<< "invalid register" << endl;
                    cout << "invalid register" << endl;
                    continue;
            }
            else
            {

                out = con_ins + con_rd + "0000";

                cout << ins << endl;
                cout << out << endl;

                out = convert_Bin_to_Hex(con_ins) + convert_Bin_to_Hex(con_rd) + "0";

                cout << out << endl;
                outFile<< out << endl;
            }
        }

        else if(ins == "dsp")
        {
            con_ins = check_instruction(ins);

            out = con_ins +"00000000";

            cout << ins << endl;
            cout << out << endl;

            out = convert_Bin_to_Hex(con_ins) +"00";

            cout << out << endl;
            outFile<< out << endl;

        }
        else
        {
             outFile<< "Invalid instruction" << endl;
             cout<< "Invalid instruction" << endl;
        }

    }
    inFile.close();
    outFile.close();





}
