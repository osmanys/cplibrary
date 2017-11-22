#include <bits/stdc++.h>
#define LENGTH_MAX_pcs 200
#define LENGTH_pcs 15
#define LENGTH_MOVQ 8
#define LENGTH_MOVR 4
#define LENGTH_MOVB 4
#define LENGTH_MOVN 8
#define LENGTH_MOVP 3
#define LENGTH_MOVPWE 2
#define LENGTH_MOVPWN 1
#define LENGTH_MOVPBE 2
#define LENGTH_MOVPBN 1

using namespace std;
int wpcs[15] = { 1, 10, 11, 12, 13, 20, 21, 22, 23, 30, 31, 32, 33, 40, 41 };
int bpcs[15] = { 101, 110, 111, 112, 113, 120, 121, 122, 123, 130, 131, 132, 133, 140, 141 };
int movQ[8][2] = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 } };
int movR[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
int movB[4][2] = { { -1, -1 }, { -1, 1 }, { 1, 1 }, { 1, -1 } };
int movN[8][2] = { { -2, -1 }, { -2, 1 }, { -1, -2 }, { -1, 2 }, { 1, -2 }, { 1, 2 }, { 2, -1 }, { 2, 1 } };
int movPWE[2][2] = { { 1, -1 }, { 1, 1 } };
int movPWN[1][2] = { { 1, 0 } };
int movPBE[2][2] = { { -1, -1 }, { -1, 1 } };
int movPBN[1][2] = { { -1, 0 } };

bool alfabeta(int brd[4][4], int pcs[LENGTH_MAX_pcs], int depth, bool white){
    if (!depth){
        if (!pcs[101])
            return true;
        return false;
    }
    else{
        if (white){
            for (int i = 0; i < LENGTH_pcs; i++){
                int p = wpcs[i];
                if (pcs[p]){
                    int rowP = (pcs[p] - 1) / 4;
                    int colP = (pcs[p] - 1) % 4;
                    switch (p){
                        case 1:
                            for (int j = 0; j < LENGTH_MOVQ; j++){
                                int rj = movQ[j][0];
                                int cj = movQ[j][1];
                                for (int k = 1; k < 4; k++){
                                    int rk = rj * k + rowP;
                                    int ck = cj * k + colP;
                                    if (rk < 0 || rk > 3 || ck < 0 || ck > 3 || (brd[rk][ck] > 0 && brd[rk][ck] < LENGTH_MAX_pcs / 2))
                                        break;

                                    int removed = 0;
                                    if (brd[rk][ck] > LENGTH_MAX_pcs / 2){
                                        if (brd[rk][ck] == 101)
                                            return true;
                                        removed = brd[rk][ck];
                                        pcs[removed] = 0;
                                    }
                                    brd[rowP][colP] = 0;
                                    brd[rk][ck] = p;
                                    pcs[p] = rk * 4 + ck + 1;

                                    bool alfa = alfabeta(brd, pcs, depth - 1, false);

                                    brd[rowP][colP] = p;
                                    brd[rk][ck] = 0;
                                    pcs[p] = rowP * 4 + colP + 1;
                                    if (removed){
                                        brd[rk][ck] = removed;
                                        pcs[removed] = rk * 4 + ck + 1;
                                    }
                                    if (alfa)
                                        return true;
                                    if (removed)
                                        break;
                                }
                            }
                            break;
                        case 10:
                        case 11:
                        case 12:
                        case 13:
                            for (int j = 0; j < LENGTH_MOVR; j++)
                            {
                                int rj = movR[j][0];
                                int cj = movR[j][1];
                                for (int k = 1; k < 4; k++)
                                {
                                    int rk = rj * k + rowP;
                                    int ck = cj * k + colP;
                                    if (rk < 0 || rk > 3 || ck < 0 || ck > 3 || (brd[rk][ck] > 0 && brd[rk][ck] < LENGTH_MAX_pcs / 2))
                                        break;

                                    int removed = 0;
                                    if (brd[rk][ck] > LENGTH_MAX_pcs / 2)
                                    {
                                        if (brd[rk][ck] == 101)
                                            return true;
                                        removed = brd[rk][ck];
                                        pcs[removed] = 0;
                                    }
                                    brd[rowP][colP] = 0;
                                    brd[rk][ck] = p;
                                    pcs[p] = rk * 4 + ck + 1;

                                    bool alfa = alfabeta(brd, pcs, depth - 1, false);

                                    brd[rowP][colP] = p;
                                    brd[rk][ck] = 0;
                                    pcs[p] = rowP * 4 + colP + 1;
                                    if (removed)
                                    {
                                        brd[rk][ck] = removed;
                                        pcs[removed] = rk * 4 + ck + 1;
                                    }
                                    if (alfa)
                                        return true;
                                    if (removed)
                                        break;
                                }
                            }
                            break;
                        case 20:
                        case 21:
                        case 22:
                        case 23:
                            for (int j = 0; j < LENGTH_MOVB; j++)
                            {
                                int rj = movB[j][0];
                                int cj = movB[j][1];
                                for (int k = 1; k < 4; k++)
                                {
                                    int rk = rj * k + rowP;
                                    int ck = cj * k + colP;
                                    if (rk < 0 || rk > 3 || ck < 0 || ck > 3 || (brd[rk][ck] > 0 && brd[rk][ck] < LENGTH_MAX_pcs / 2))
                                        break;

                                    int removed = 0;
                                    if (brd[rk][ck] > LENGTH_MAX_pcs / 2)
                                    {
                                        if (brd[rk][ck] == 101)
                                            return true;
                                        removed = brd[rk][ck];
                                        pcs[removed] = 0;
                                    }
                                    brd[rowP][colP] = 0;
                                    brd[rk][ck] = p;
                                    pcs[p] = rk * 4 + ck + 1;

                                    bool alfa = alfabeta(brd, pcs, depth - 1, false);

                                    brd[rowP][colP] = p;
                                    brd[rk][ck] = 0;
                                    pcs[p] = rowP * 4 + colP + 1;
                                    if (removed)
                                    {
                                        brd[rk][ck] = removed;
                                        pcs[removed] = rk * 4 + ck + 1;
                                    }
                                    if (alfa)
                                        return true;
                                    if (removed)
                                        break;
                                }
                            }
                            break;
                        case 30:
                        case 31:
                        case 32:
                        case 33:
                            for (int j = 0; j < LENGTH_MOVN; j++)
                            {
                                int rk = movN[j][0] + rowP;
                                int ck = movN[j][1] + colP;
                                if (rk < 0 || rk > 3 || ck < 0 || ck > 3 || (brd[rk][ck] > 0 && brd[rk][ck] < LENGTH_MAX_pcs / 2))
                                    continue;

                                int removed = 0;
                                if (brd[rk][ck] > LENGTH_MAX_pcs / 2)
                                {
                                    if (brd[rk][ck] == 101)
                                        return true;
                                    removed = brd[rk][ck];
                                    pcs[removed] = 0;
                                }
                                brd[rowP][colP] = 0;
                                brd[rk][ck] = p;
                                pcs[p] = rk * 4 + ck + 1;

                                bool alfa = alfabeta(brd, pcs, depth - 1, false);

                                brd[rowP][colP] = p;
                                brd[rk][ck] = 0;
                                pcs[p] = rowP * 4 + colP + 1;
                                if (removed)
                                {
                                    brd[rk][ck] = removed;
                                    pcs[removed] = rk * 4 + ck + 1;
                                }
                                if (alfa)
                                    return true;
                            }
                            break;
                        case 40:
                        case 41:
                            for (int j = 0; j < LENGTH_MOVPWE; j++)
                            {
                                int rj = movPWE[j][0];
                                int cj = movPWE[j][1];
                                for (int k = 1; k < 2; k++)
                                {
                                    int rk = rj * k + rowP;
                                    int ck = cj * k + colP;
                                    if (rk < 0 || rk > 3 || ck < 0 || ck > 3 || (brd[rk][ck] > 0 && brd[rk][ck] < 100) || brd[rk][ck] == 0)
                                        break;

                                    int removed = 0;
                                    if (brd[rk][ck] > 100)
                                    {
                                        if (brd[rk][ck] == 101)
                                            return true;
                                        removed = brd[rk][ck];
                                        pcs[removed] = 0;
                                    }
                                    brd[rowP][colP] = 0;
                                    brd[rk][ck] = p;
                                    pcs[p] = rk * 4 + ck + 1;

                                    int alfa = false;
                                    if(rk == 3)
                                    {
                                        int promote = pcs[12] ? 13 : 12;
                                        brd[rk][ck] = promote;
                                        pcs[p] = 0;
                                        pcs[promote] = rk * 4 + ck + 1;
                                        alfa = alfabeta(brd, pcs, depth - 1, false);
                                        brd[rk][ck] = p;
                                        pcs[promote] = 0;
                                        pcs[p] =  rk * 4 + ck + 1;

                                        if (!alfa)
                                        {
                                            promote = pcs[22] ? 23 : 22;
                                            brd[rk][ck] = promote;
                                            pcs[p] = 0;
                                            pcs[promote] = rk * 4 + ck + 1;
                                            alfa = alfabeta(brd, pcs, depth - 1, false);
                                            brd[rk][ck] = p;
                                            pcs[promote] = 0;
                                            pcs[p] =  rk * 4 + ck + 1;
                                        }

                                        if (!alfa)
                                        {
                                            promote = pcs[32] ? 33 : 32;
                                            brd[rk][ck] = promote;
                                            pcs[p] = 0;
                                            pcs[promote] = rk * 4 + ck + 1;
                                            alfa = alfabeta(brd, pcs, depth - 1, false);
                                            brd[rk][ck] = p;
                                            pcs[promote] = 0;
                                            pcs[p] =  rk * 4 + ck + 1;
                                        }
                                    }
                                    else
                                        alfa = alfabeta(brd, pcs, depth - 1, false);

                                    brd[rowP][colP] = p;
                                    brd[rk][ck] = 0;
                                    pcs[p] = rowP * 4 + colP + 1;
                                    if (removed > 0)
                                    {
                                        brd[rk][ck] = removed;
                                        pcs[removed] = rk * 4 + ck + 1;
                                    }
                                    if (alfa)
                                        return true;
                                    if (removed > 0)
                                        break;
                                }
                            }
                            for (int j = 0; j < LENGTH_MOVPWN; j++)
                            {
                                int rj = movPWN[j][0];
                                int cj = movPWN[j][1];
                                for (int k = 1; k < 2; k++)
                                {
                                    int rk = rj * k + rowP;
                                    int ck = cj * k + colP;
                                    if (rk < 0 || rk > 3 || ck < 0 || ck > 3 || brd[rk][ck] != 0)
                                        break;

                                    int removed = 0;
                                    if (brd[rk][ck] > 100)
                                    {
                                        if (brd[rk][ck] == 101)
                                            return true;
                                        removed = brd[rk][ck];
                                        pcs[removed] = 0;
                                    }
                                    brd[rowP][colP] = 0;
                                    brd[rk][ck] = p;
                                    pcs[p] = rk * 4 + ck + 1;

                                    int alfa = false;
                                    if (rk == 3)
                                    {
                                        int promote = pcs[12] ? 13 : 12;
                                        brd[rk][ck] = promote;
                                        pcs[p] = 0;
                                        pcs[promote] = rk * 4 + ck + 1;
                                        alfa = alfabeta(brd, pcs, depth - 1, false);
                                        brd[rk][ck] = p;
                                        pcs[promote] = 0;
                                        pcs[p] =  rk * 4 + ck + 1;

                                        if (!alfa)
                                        {
                                            promote = pcs[22] ? 23 : 22;
                                            brd[rk][ck] = promote;
                                            pcs[p] = 0;
                                            pcs[promote] = rk * 4 + ck + 1;
                                            alfa = alfabeta(brd, pcs, depth - 1, false);
                                            brd[rk][ck] = p;
                                            pcs[promote] = 0;
                                            pcs[p] =  rk * 4 + ck + 1;
                                        }

                                        if (!alfa)
                                        {
                                            promote = pcs[32] ? 33 : 32;
                                            brd[rk][ck] = promote;
                                            pcs[p] = 0;
                                            pcs[promote] = rk * 4 + ck + 1;
                                            alfa = alfabeta(brd, pcs, depth - 1, false);
                                            brd[rk][ck] = p;
                                            pcs[promote] = 0;
                                            pcs[p] =  rk * 4 + ck + 1;
                                        }
                                    }
                                    else
                                        alfa = alfabeta(brd, pcs, depth - 1, false);

                                    brd[rowP][colP] = p;
                                    brd[rk][ck] = 0;
                                    pcs[p] = rowP * 4 + colP + 1;
                                    if (removed > 0)
                                    {
                                        brd[rk][ck] = removed;
                                        pcs[removed] = rk * 4 + ck + 1;
                                    }
                                    if (alfa)
                                        return true;
                                    if (removed > 0)
                                        break;
                                }
                            }
                            break;
                    }
                }
            }
            return false;
        }
        else
        {
            for (int i = 0; i < LENGTH_pcs; i++){
                int p = bpcs[i];
                if (pcs[p])
                {
                    int rowP = (pcs[p] - 1) / 4;
                    int colP = (pcs[p] - 1) % 4;
                    switch (p)
                    {
                        case 101:
                            for (int j = 0; j < LENGTH_MOVQ; j++)
                            {
                                int rj = movQ[j][0];
                                int cj = movQ[j][1];
                                for (int k = 1; k < 4; k++)
                                {
                                    int rk = rj * k + rowP;
                                    int ck = cj * k + colP;
                                    if (rk < 0 || rk > 3 || ck < 0 || ck > 3 || brd[rk][ck] > LENGTH_MAX_pcs / 2)
                                        break;

                                    int removed = 0;
                                    if (brd[rk][ck] > 0 && brd[rk][ck] < LENGTH_MAX_pcs / 2)
                                    {
                                        if (brd[rk][ck] == 1)
                                            return false;
                                        removed = brd[rk][ck];
                                        pcs[removed] = 0;
                                    }
                                    brd[rowP][colP] = 0;
                                    brd[rk][ck] = p;
                                    pcs[p] = rk * 4 + ck + 1;

                                    bool beta = alfabeta(brd, pcs, depth - 1, true);

                                    brd[rowP][colP] = p;
                                    brd[rk][ck] = 0;
                                    pcs[p] = rowP * 4 + colP + 1;
                                    if (removed)
                                    {
                                        brd[rk][ck] = removed;
                                        pcs[removed] = rk * 4 + ck + 1;
                                    }
                                    if (!beta)
                                        return false;
                                    if (removed)
                                        break;
                                }
                            }
                            break;
                        case 110:
                        case 111:
                        case 112:
                        case 113:
                            for (int j = 0; j < LENGTH_MOVR; j++)
                            {
                                int rj = movR[j][0];
                                int cj = movR[j][1];
                                for (int k = 1; k < 4; k++)
                                {
                                    int rk = rj * k + rowP;
                                    int ck = cj * k + colP;
                                    if (rk < 0 || rk > 3 || ck < 0 || ck > 3 || brd[rk][ck] > LENGTH_MAX_pcs / 2)
                                        break;

                                    int removed = 0;
                                    if (brd[rk][ck] > 0 && brd[rk][ck] < LENGTH_MAX_pcs / 2)
                                    {
                                        if (brd[rk][ck] == 1)
                                            return false;
                                        removed = brd[rk][ck];
                                        pcs[removed] = 0;
                                    }
                                    brd[rowP][colP] = 0;
                                    brd[rk][ck] = p;
                                    pcs[p] = rk * 4 + ck + 1;

                                    bool beta = alfabeta(brd, pcs, depth - 1, true);

                                    brd[rowP][colP] = p;
                                    brd[rk][ck] = 0;
                                    pcs[p] = rowP * 4 + colP + 1;
                                    if (removed)
                                    {
                                        brd[rk][ck] = removed;
                                        pcs[removed] = rk * 4 + ck + 1;
                                    }
                                    if (!beta)
                                        return false;
                                    if (removed)
                                        break;
                                }
                            }
                            break;
                        case 120:
                        case 121:
                        case 122:
                        case 123:
                            for (int j = 0; j < LENGTH_MOVB; j++)
                            {
                                int rj = movB[j][0];
                                int cj = movB[j][1];
                                for (int k = 1; k < 4; k++)
                                {
                                    int rk = rj * k + rowP;
                                    int ck = cj * k + colP;
                                    if (rk < 0 || rk > 3 || ck < 0 || ck > 3 || brd[rk][ck] > LENGTH_MAX_pcs / 2)
                                        break;

                                    int removed = 0;
                                    if (brd[rk][ck] > 0 && brd[rk][ck] < LENGTH_MAX_pcs / 2)
                                    {
                                        if (brd[rk][ck] == 1)
                                            return false;
                                        removed = brd[rk][ck];
                                        pcs[removed] = 0;
                                    }
                                    brd[rowP][colP] = 0;
                                    brd[rk][ck] = p;
                                    pcs[p] = rk * 4 + ck + 1;

                                    bool beta = alfabeta(brd, pcs, depth - 1, true);

                                    brd[rowP][colP] = p;
                                    brd[rk][ck] = 0;
                                    pcs[p] = rowP * 4 + colP + 1;
                                    if (removed)
                                    {
                                        brd[rk][ck] = removed;
                                        pcs[removed] = rk * 4 + ck + 1;
                                    }
                                    if (!beta)
                                        return false;
                                    if (removed)
                                        break;
                                }
                            }
                            break;
                        case 130:
                        case 131:
                        case 132:
                        case 133:
                            for (int j = 0; j < LENGTH_MOVN; j++)
                            {
                                int rk = movN[j][0] + rowP;
                                int ck = movN[j][1] + colP;
                                if (rk < 0 || rk > 3 || ck < 0 || ck > 3 || brd[rk][ck] > LENGTH_MAX_pcs / 2)
                                    continue;

                                int removed = 0;
                                if (brd[rk][ck] > 0 && brd[rk][ck] < LENGTH_MAX_pcs / 2)
                                {
                                    if (brd[rk][ck] == 1)
                                        return false;
                                    removed = brd[rk][ck];
                                    pcs[removed] = 0;
                                }
                                brd[rowP][colP] = 0;
                                brd[rk][ck] = p;
                                pcs[p] = rk * 4 + ck + 1;

                                bool beta = alfabeta(brd, pcs, depth - 1, true);

                                brd[rowP][colP] = p;
                                brd[rk][ck] = 0;
                                pcs[p] = rowP * 4 + colP + 1;
                                if (removed)
                                {
                                    brd[rk][ck] = removed;
                                    pcs[removed] = rk * 4 + ck + 1;
                                }
                                if (!beta)
                                    return false;
                            }
                            break;
                        case 140:
                        case 141:
                            for (int j = 0; j < LENGTH_MOVPBE; j++)
                            {
                                int rj = movPBE[j][0];
                                int cj = movPBE[j][1];
                                for (int k = 1; k < 2; k++)
                                {
                                    int rk = rj * k + rowP;
                                    int ck = cj * k + colP;
                                    if (rk < 0 || rk > 3 || ck < 0 || ck > 3 || brd[rk][ck] > 100 || brd[rk][ck] == 0)
                                        break;

                                    int removed = 0;
                                    if (brd[rk][ck] > 0 && brd[rk][ck] < 100)
                                    {
                                        if (brd[rk][ck] == 1)
                                            return false;
                                        removed = brd[rk][ck];
                                        pcs[removed] = 0;
                                    }
                                    brd[rowP][colP] = 0;
                                    brd[rk][ck] = p;
                                    pcs[p] = rk * 4 + ck + 1;

                                    int beta = true;
                                    if (rk == 0)
                                    {
                                        int promote = pcs[112] ? 113 : 112;
                                        brd[rk][ck] = promote;
                                        pcs[p] = 0;
                                        pcs[promote] = rk * 4 + ck + 1;
                                        beta = alfabeta(brd, pcs, depth - 1, true);
                                        brd[rk][ck] = p;
                                        pcs[promote] = 0;
                                        pcs[p] =  rk * 4 + ck + 1;

                                        if (beta)
                                        {
                                            promote = pcs[122] ? 123 : 122;
                                            brd[rk][ck] = promote;
                                            pcs[p] = 0;
                                            pcs[promote] = rk * 4 + ck + 1;
                                            beta = alfabeta(brd, pcs, depth - 1, true);
                                            brd[rk][ck] = p;
                                            pcs[promote] = 0;
                                            pcs[p] =  rk * 4 + ck + 1;
                                        }

                                        if (beta)
                                        {
                                            promote = pcs[132] ? 133 : 132;
                                            brd[rk][ck] = promote;
                                            pcs[p] = 0;
                                            pcs[promote] = rk * 4 + ck + 1;
                                            beta = alfabeta(brd, pcs, depth - 1, true);
                                            brd[rk][ck] = p;
                                            pcs[promote] = 0;
                                            pcs[p] =  rk * 4 + ck + 1;
                                        }
                                    }
                                    else
                                        beta = alfabeta(brd, pcs, depth - 1, true);

                                    brd[rowP][colP] = p;
                                    brd[rk][ck] = 0;
                                    pcs[p] = rowP * 4 + colP + 1;
                                    if (removed > 0)
                                    {
                                        brd[rk][ck] = removed;
                                        pcs[removed] = rk * 4 + ck + 1;
                                    }
                                    if (!beta)
                                        return false;
                                    if (removed > 0)
                                        break;
                                }
                            }
                            for (int j = 0; j < LENGTH_MOVPBN; j++)
                            {
                                int rj = movPBN[j][0];
                                int cj = movPBN[j][1];
                                for (int k = 1; k < 2; k++)
                                {
                                    int rk = rj * k + rowP;
                                    int ck = cj * k + colP;
                                    if (rk < 0 || rk > 3 || ck < 0 || ck > 3 || brd[rk][ck] != 0)
                                        break;

                                    int removed = 0;
                                    if (brd[rk][ck] > 0 && brd[rk][ck] < 100)
                                    {
                                        if (brd[rk][ck] == 1)
                                            return false;
                                        removed = brd[rk][ck];
                                        pcs[removed] = 0;
                                    }
                                    brd[rowP][colP] = 0;
                                    brd[rk][ck] = p;
                                    pcs[p] = rk * 4 + ck + 1;

                                    int beta = true;
                                    if (rk == 0)
                                    {
                                        int promote = pcs[112] ? 113 : 112;
                                        brd[rk][ck] = promote;
                                        pcs[p] = 0;
                                        pcs[promote] = rk * 4 + ck + 1;
                                        beta = alfabeta(brd, pcs, depth - 1, true);
                                        brd[rk][ck] = p;
                                        pcs[promote] = 0;
                                        pcs[p] =  rk * 4 + ck + 1;

                                        if (beta)
                                        {
                                            promote = pcs[122] ? 123 : 122;
                                            brd[rk][ck] = promote;
                                            pcs[p] = 0;
                                            pcs[promote] = rk * 4 + ck + 1;
                                            beta = alfabeta(brd, pcs, depth - 1, true);
                                            brd[rk][ck] = p;
                                            pcs[promote] = 0;
                                            pcs[p] =  rk * 4 + ck + 1;
                                        }

                                        if (beta)
                                        {
                                            promote = pcs[132] ? 133 : 132;
                                            brd[rk][ck] = promote;
                                            pcs[p] = 0;
                                            pcs[promote] = rk * 4 + ck + 1;
                                            beta = alfabeta(brd, pcs, depth - 1, true);
                                            brd[rk][ck] = p;
                                            pcs[promote] = 0;
                                            pcs[p] =  rk * 4 + ck + 1;
                                        }
                                    }
                                    else
                                        beta = alfabeta(brd, pcs, depth - 1, true);

                                    brd[rowP][colP] = p;
                                    brd[rk][ck] = 0;
                                    pcs[p] = rowP * 4 + colP + 1;
                                    if (removed > 0)
                                    {
                                        brd[rk][ck] = removed;
                                        pcs[removed] = rk * 4 + ck + 1;
                                    }
                                    if (!beta)
                                        return false;
                                    if (removed > 0)
                                        break;
                                }
                            }
                            break;
                    }
                }
            }
            return true;
        }
    }
}

int g, w, b, m, row, piece;
char t, col;

int main(){
    cin >> g;
    while (g--){
        int brd[4][4] = {0};
        int pcs[LENGTH_MAX_pcs] = {0};
        cin >> w >> b >> m;
        while (w--){
            cin >> t >> col >> row;
            switch (t){
                case 'Q':
                    piece = 1;
                    break;
                case 'R':
                    if (pcs[10])
                        piece = 11;
                    else
                        piece = 10;
                    break;
                case 'B':
                    if (pcs[20])
                        piece = 21;
                    else
                        piece = 20;
                    break;
                case 'N':
                    if (pcs[30])
                        piece = 31;
                    else
                        piece = 30;
                    break;
                case 'P':
                    if (pcs[40])
                        piece = 41;
                    else
                        piece = 40;
                    break;
            }
            brd[row - 1][(int)col - 65] = piece;
            pcs[piece] = (row - 1) * 4 + ((int)col - 65) + 1;
        }
        while (b--){
            cin >> t >> col >> row;
            switch (t){
                case 'Q':
                    piece = 101;
                    break;
                case 'R':
                    if (pcs[110])
                        piece = 111;
                    else
                        piece = 110;
                    break;
                case 'B':
                    if (pcs[120])
                        piece = 121;
                    else
                        piece = 120;
                    break;
                case 'N':
                    if (pcs[130])
                        piece = 131;
                    else
                        piece = 130;
                    break;
                case 'P':
                    if (pcs[140])
                        piece = 141;
                    else
                        piece = 140;
                    break;
            }
            brd[row - 1][(int)col - 65] = piece;
            pcs[piece] = (row - 1) * 4 + ((int)col - 65) + 1;
        }
        cout << (alfabeta(brd, pcs, m, true) ? "YES" : "NO") << '\n';
    }
    return 0;
}
