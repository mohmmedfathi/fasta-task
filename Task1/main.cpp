#include<bits/stdc++.h>

using namespace std;

int main()
{
    fstream Fastaq,FastaTxt;
    fstream qualities;
    Fastaq.open("ERR3481910_1.fastq",ios::in); // to read

    if (!(Fastaq.is_open()))
    {
        printf("Cannot open the fastaq to read!");
        exit(0);
    }
    FastaTxt.open("FastaText.txt",ios::out);
    if (!(FastaTxt.is_open()))
    {
        printf("Cannot open file to write Fastaq.Text!");
        exit(0);
    }
    // to write
    qualities.open("qualities.txt",ios::out);
    if (!(qualities.is_open()))
    {
        printf("Cannot open file to write qualities!");
        exit(0);
    }

    int L = 0;
    FastaTxt<<"ID\tSequence\tQuality\t";
    for (int i = 1; i<=5; i++)
    {
        //string s = 'C' + i;
        FastaTxt << 'C'<<i << "\t";
        qualities << 'C' << i << "\t";
    }
    FastaTxt<<"\n";
    qualities <<"\n";
    int n = 200;
    while (n-->0)
    {
        string line;
        getline(Fastaq,line);
        int ch_first,ch_last;
        if (L==0)
        {
            for (int i =0; line[i]!=' '; i++)
                FastaTxt<<line[i];

            FastaTxt<<"\t";
            L++;
        }
        else if (L==1)
        {
            // write line;
            for (int i = 0; i<5; i++)
                FastaTxt << line[i];
            FastaTxt << "\t";
            L++;
        }
        else if (L==2)
        {
            L++;
            continue;
        }
        else if (L==3)
        {
            int quality[5];
            for (int i = 0; i<5; i++)
            {
                quality[i] = int(line[i]) - 33;
                FastaTxt << line[i];
            }
            FastaTxt << "\t";
            for (int i:quality)
            {
                FastaTxt << i <<"\t";
                qualities << i << "\t";
            }
            L=0;
            FastaTxt << "\n";
            qualities << "\n";
        }
    }
    cout << "content copied!" << endl;
    Fastaq.close();
    FastaTxt.close();
    qualities.close();
}
