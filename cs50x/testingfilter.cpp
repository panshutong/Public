#include<stdio.h>
int main(){
    int bmp[3][3]={{1,1,1},{6,3,7},{4,7,2}};
    int tem[3][3];
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int a=0;
            int times=0;
            for(int x=i-1;x<=i+1;x++){
                if(x==-1||x==3){
                    continue;
                }
                else{
                    for(int y=j-1;y<=j+1;y++){
                        if(y==-1||y==3){
                            continue;
                            
                        }
                        else{
                            a+=bmp[x][y];
                            times++;
                        }
                    }
                }
            }
            tem[i][j]=a/times;
        }
    }
    return 0;
}

// allocate temp as same dimensions (use malloc for variable sizes)
RGBTRIPLE(*temp)[width] = malloc(sizeof(RGBTRIPLE) * height * width);
if (!temp) { /* handle error */ }

for (int i = 0; i < height; i++)
{
    for (int j = 0; j < width; j++)
    {
        int sumB = 0;
        int sumG = 0;
        int sumR = 0;
        int count = 0;

        for (int x = i - 1; x <= i + 1; x++)
        {
            if (x < 0 || x >= height) continue;
            for (int y = j - 1; y <= j + 1; y++)
            {
                if (y < 0 || y >= width) continue;
                sumB += image[x][y].rgbtBlue;
                sumG += image[x][y].rgbtGreen;
                sumR += image[x][y].rgbtRed;
                count++;
            }
        }

        // round to nearest integer
        temp[i][j].rgbtBlue  = (uint8_t)((sumB + count / 2) / count);
        temp[i][j].rgbtGreen = (uint8_t)((sumG + count / 2) / count);
        temp[i][j].rgbtRed   = (uint8_t)((sumR + count / 2) / count);
    }
}

// copy temp back to image (or write temp out)
for (int i = 0; i < height; i++)
    for (int j = 0; j < width; j++)
        image[i][j] = temp[i][j];

free(temp);