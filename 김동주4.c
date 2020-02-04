#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STUDENT 20
#define CLASS 5
#define ALL 100

int scores[CLASS][STUDENT];

void Score_setting();
void Class_average();
void Student_score();

int main() {
	Score_setting();
	printf("\n");
	Class_average();
	printf("\n");
	Student_score();
	return 0;
}

//�������� ���� �����ϱ�.
void Score_setting() {
	int i;
	int j;
	int temp;
	int class = 1;
	srand(time(NULL));
	for (i = 0; i < CLASS; i++) {
		printf("%d���� ���� : ", class);
		for (j = 0; j < STUDENT; j++) {
			temp = rand() % 101;
			scores[i][j] = temp;
			printf("%d ", scores[i][j]);
		}
		printf("\n");
		class++;
	}
}
//����, �ݺ� ����/�ְ���, �ݺ� �ְ� ����
void Class_average() {
	int i;
	int j;
	int least;
	int k;
	int temp;
	int class = 1;
	float class_average_sum = 0;
	float class_average;

	for (i = 0; i < CLASS; i++) {
		for (j = 0; j < STUDENT - 1; j++) {
			least = j;
			for (k = j + 1; k < STUDENT; k++) {
				if (scores[i][k] < scores[i][least]) {
					temp = scores[i][k];
					scores[i][k] = scores[i][least];
					scores[i][least] = temp;
				}
			}
		}
	}
	for (i = 0; i < CLASS; i++) {
		class_average_sum = 0;
		printf("���ĵ� %d���� ����: ", class);
		for (j = 0; j < STUDENT; j++) {
			printf("%d ", scores[i][j]);
			class_average_sum = class_average_sum + scores[i][j];
		}
		class_average = class_average_sum / STUDENT;
		printf("\n");
		printf("%d���� �������� %d���̰� �ְ����� %d���̴�.\n", class, scores[i - 1][k], scores[i][least + 1]);
		printf("%d���� ��� ������ %.2f���Դϴ�.\n", class, class_average);
		printf("\n");
		class++;
	}
	class_average_sum = 0;
}
//��ü �л� ���, ����, �ְ���
void Student_score() {
	int i;
	int j;
	int k = 0;
	int least;
	int temp;
	float average_sum = 0;
	float average;
	int all_student[ALL];

	for (i = 0; i < CLASS; i++) {
		for (j = 0; j < STUDENT; j++) {
			average_sum += scores[i][j];
		}
	}
	average = average_sum / (ALL);
	printf("��ü �л��� ��ռ����� %.2f�� �Դϴ�.\n", average);

	for (i = 0; i < CLASS; i++) {
		for (j = 0; j < STUDENT; j++) {
			all_student[k] = scores[i][j];
			k++;
		}
	}
	for (i = 0; i < ALL - 1; i++) {
		least = i;
		for (j = i + 1; j < ALL; j++) {
			if (all_student[j] < all_student[least]) {
				least = j;
			}
			temp = all_student[i];
			all_student[i] = all_student[least];
			all_student[least] = temp;
		}
	}
	printf("��ü �л��� �������� %d���̰� �ְ����� %d���̴�.\n", all_student[0], all_student[ALL - 1]);
}