#include "huffman.h"

char text[10000];
double w[10000];
int temp[100];

int main(void)
{
	//��ȡ�����ַ���
	FILE* fp = NULL;
	fp = fopen("textfile.txt", "r");
	fgets(text, 8000, (FILE*)fp);
	fclose(fp);

	//�ַ���ͳ��
	TextFrequencyAnalysis();

	HuffmanCode HT;
	huffmanCoding(HT, w, 26); //������������

	Huffman HC;
	HuffCoding(HT, HC, 26); //��������������

	//��������д��codefile
	int length = strlen(text);
	fp = fopen("codefile.txt", "w");
	for (int i = 0; i < length; i++)
	{
		fputs(HC[text[i] - 'a' + 1], fp);
		fputc(' ', fp);
	}
	fclose(fp);

	//����
	char zimu[27] = { ' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r',
		's','t','u','v','w','x','y','z' };
	fp = fopen("codefile.txt", "r");

	int i, j = 0;
	char st[10000];
	char op[100];
	fgets(st, 10000, (FILE*)fp);
	length = strlen(st);
	fclose(fp);

	fp = fopen("decodefile.txt", "w");
	int ans;
	int flag = 0;

	for (i = 0; i < length; i++)
	{
		if (st[i] != ' ')
			op[j++] = st[i];
		else
		{
			op[j] = '\0';
			j = 0;
			for (int k = 1; k <= 26; k++)
			{
				int tlenth = strlen(op);
				flag = 1;
				for (int l = 0; l < tlenth; l++)
				{

					if (op[l] != HC[k][l])
					{
						flag = 0;
						break;
					}
				}

				if (flag)
				{
					ans = k;
					break;
				}
			}
			fputc(zimu[ans], fp);
		}
	}
	fclose(fp);



	return 0;
}