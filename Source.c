


#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <process.h>

#define size 255 


int main()
{
	//FILE* file = fopen("D:\Visual_Studio_2019\Lab_5_VL\Lab_5_VL\input3.txt", "a+");

	//fprint(file, "test1");


	//fclose(file);

	//return 0;
//}

	//char c;
	float fp, fp2, fp3;
	long l;
	int i;
	char line[size]; // char-масив, line-назва масиву
	system("chcp 1251");
	//	FILE* S1, * S2;
	//	int x, y;

	FILE* file = fopen("D:\Visual_Studio_2019\Lab_5_VL\Lab_5_VL\input3.txt", "a"); // вказ≥вник типу даних файл , file- назва вказ≥вника, fopen - функц≥€ повертаЇ весь в≥дкритий файл, 1 параметр функц≥њ - €кий файл або де в≥н знаходитьс€,
	//2 параметр - метод в≥дкритт€ файлу  "r" читати  "w" запис  "a" запис без видаленн€ ≥нфорамц≥њ,
	//"r+" - в≥дкрити файл дл€ читанн€ та запису (файл повинен ≥снувати);
	//"w+"  - в≥дкрити порожн≥й файл дл€ читанн€ та запису; якщо файл ≥снуЇ, його вм≥ст перезаписуЇтьс€. якщо файл не ≥снуЇ, створюЇтьс€ новий файл.
	//"a+"  -в≥дкрити файл дл€ читанн€ та доповненн€, €кщо файл не ≥снуЇ, то в≥н створюЇтьс€. 
	//зв≥дси зчитуютьс€ дан≥

//fprintf(file, "1");

	if ((file = fopen("input3.txt", "r+")) == NULL) //NULL-нульовий вказ≥вник
	{
		printf("error");
		//getchar();
		return 0;
	}
	else
	{
		printf("file was opened");

	}
	for (i = 0; i < 5; i++)
	{
		fgets(line, 255, file);// 1 парамет - масив з €ким працюЇмо, 2 параметр - к≥льк≥сть символ≥в €к≥ хочемо зчитати, 3 параметр - з €ким файлом працюЇмо
	//функц≥€ fgets() працюЇ построково - перший виклик = 1 р€док, другий виклик = 2 р€док(можна виконати у вигл€д≥ циклу)
		printf("\n\n%s", line);
	}
	//
	//The prototype functions fseek :
	//1
	//
	////int fseek(FILE * filestream, long int offset, int origin);
	//SEEK_SET 	Top of file
	//SEEK_CUR 	The current position of the file
	//SEEK_END 	End of file
	// ¬становити покажчик на початок файлу:
	fseek(file, 0L, SEEK_SET); //0L - зм≥на позиц≥њ (у байт) в≥дносно початку файла

	// Read data back from file:
	fscanf(file, "%s", line);
	fscanf(file, "%ld", &l);
	fscanf(file, "%f", &fp);
	fscanf(file, "%f", &fp2);
	fscanf(file, "%f", &fp3);
	//fscanf(file, "%c", &c);  
	// Note: fscanf is deprecated; consider using fscanf_s instead

	// Output data read:

	printf("\n Line = %s\n", line);
	printf("x1 = %ld\n", l);
	printf("x2 = %f\n", fp);
	printf("N = %f\n", fp2);
	printf("d = %f\n", fp3);
	//printf("N =%c\n", c);


	///------------------------------------------------------------------------------------------
	//int f;
	//
	//fscanf(file, "%s%d", line, &f);
	////&a вказуЇмо адресу куди записуЇтьс€ значенн€
	//
	//
	//int* b;
	//b = &f;
	//
	////n1 = getw
	//
	////fprintf(file, "test2"); 
	//printf("X1 =  %d\n", *b);
		// треба закривати файл коли робotа з ним зак≥нчена
	fclose(file);



	FILE* fileTxt = fopen("result.txt", "w");

	//	fprintf(fileTxt, "\nGroup");

	fprintf(fileTxt, "\n Group - %s\n", line);
	fprintf(fileTxt, " X1 = % ld\n", l);
	fprintf(fileTxt, " X2 = % f\n", fp);
	fprintf(fileTxt, " N= % f\n", fp2);
	fprintf(fileTxt, " d = % f\n", fp3);
	fprintf(fileTxt, "You type:: %s %ld %s %f %s %f\n", "\n initial argument value x1 - ", l, "\n last argument value x2-", fp, "\n value of the number of points N -", fp2);
	
	fprintf(fileTxt, "-----------------------------------------\n");
	fprintf(fileTxt, "      N | X |       \n"
		"-------------+--------------+-------------\n");
	fprintf(fileTxt, "%s %f %s %f %s %ld %s ", " ", fp2, "          |", fp, "|", l, "|", "\n"
		"-------------+--------------+-------------\n");
	fprintf(fileTxt, "           |           |            \n"
		"-------------+--------------+-------------\n");

	fclose(fileTxt);

	
	//-------------------------------------------------------------------

	//3) «читуванн€ б≥нарного файлу
	FILE* filebin = NULL;
	int number;

	filebin = fopen("result.bin", "wb");
	if (filebin == NULL) {
		printf("Error opening file");
		//_getch();
		return 0;
	}


	fprintf(filebin, "\n Group - %s\n", line);
	fprintf(filebin, " X1 = % ld\n", l);
	fprintf(filebin, " X2 = % f\n", fp);
	fprintf(filebin, " N= % f\n", fp2);
	fprintf(filebin, " d = % f\n", fp3);
	fprintf(filebin, "You type:: %s %ld %s %f %s %f\n", "\n initial argument value x1 - ", l, "\n last argument value x2-", fp, "\n value of the number of points N -", fp2);

	//fprintf(fileTxt, "F(x) = 2 * x1, F(x) = 2 * x2\n");

	fprintf(filebin, "-----------------------------------------\n");
	fprintf(filebin, "      N | X |       \n"
		"-------------+--------------+-------------\n");
	fprintf(filebin, "%s %f %s %f %s %ld %s ", " ", fp2, "          |", fp, "|", l, "|", "\n"
		"-------------+--------------+-------------\n");
	fprintf(filebin, "           |           |            \n"
		"-------------+--------------+-------------\n");

	/*scanf("%d", &number);
	fwrite(&number, sizeof(int), 1, filebin);*/

	fclose(filebin);
	//_getch();



	return 0;
}

//result.bin size = 424 bytes
//result.txt size = 439 bytes








/*
УrФ Ц Searches file.If the file is opened successfully fopen() loads it into memoryand sets up a pointer which points to the first character in it.If the file cannot be opened fopen() returns NULL.
УrbФ Ц Open for reading in binary mode.If the file does not exist, fopen() returns NULL.
УwФ Ц Searches file.If the file exists, its contents are overwritten.If the file doesnТt exist, a new file is created.Returns NULL, if unable to open file.
УwbФ Ц  Open for writing in binary mode.If the file exists, its contents are overwritten.If the file does not exist, it will be created.
УaФ Ц Searches file.If the file is opened successfully fopen() loads it into memoryand sets up a pointer that points to the last character in it.If the file doesnТt exist, a new file is created.Returns NULL, if unable to open file.
УabФ Ц Open for append in binary mode.Data is added to the end of the file.If the file does not exist, it will be created.
Уr + Ф Ц Searches file.If is opened successfully fopen() loads it into memory and sets up a pointer which points to the first character in it.Returns NULL, if unable to open the file.
Уrb + Ф Ц Open for both readingand writing in binary mode.If the file does not exist, fopen() returns NULL.
Уw + Ф Ц Searches file.If the file exists, its contents are overwritten.If the file doesnТt exist a new file is created.Returns NULL, if unable to open file.
Уwb + Ф Ц Open for both readingand writing in binary mode.If the file exists, its contents are overwritten.If the file does not exist, it will be created.
Уa + Ф Ц Searches file.If the file is opened successfully fopen() loads it into memory and sets up a pointer which points to the last character in it.If the file doesnТt exist, a new file is created.Returns NULL, if unable to open file.
Уab + Ф Ц Open for both readingand appending in binary mode.If the file does not exist, it will be created.
*/

//“eкстовий файл(англ.textfile; застар≥ле англ.flatfile) Ч форма поданн€ посл≥довност≥ символ≥в у комп'ютер≥, де кожен символ ≥з зад≥€ного набору символ≥в кодуЇтьс€ одним байтом чи посл≥довн≥стю двох, трьох ≥ т. д. байт≥в.
//ƒв≥йковий (б≥нарний) файл (англ. binary file) Ч в широкому сенс≥: файл, що м≥стить посл≥довн≥сть дов≥льних байт≥в. Ќазва пов'€зана з тим, що байти складаютьс€ з б≥т, тобто дв≥йкових (англ. binary) цифр. 
