#include <stdio.h>
#include <string.h>
#include <locale.h>

void ex01();
void ex02();
void ex03();
void ex04();
void ex05();
void ex06();
void ex07();
void ex08();
void ex09();
void ex10();


int main() {
  setlocale(LC_ALL, "pt_BR");

  int ex_num = 0;

  printf("\e[H\e[2J");

  do {
    printf("Selecione o exercício ou digite 0 para sair\n> ");
    scanf("%d", &ex_num);

    printf("\e[H\e[2J");

    switch (ex_num) {
    case 0:
      printf("Até mais!\n");
      break;
    case 1:
      ex01();
      break;
    case 2:
      ex02();
      break;
    case 3:
      ex03();
      break;
    case 4:
      ex04();
      break;
    case 5:
      ex05();
      break;
    case 6:
      ex06();
      break;
    case 7:
      ex07();
      break;
    case 8:
      ex08();
      break;
    case 9:
      ex09();
      break;
    case 10:
      ex10();
      break;
    default:
      printf("Entrada Inválida!");
      break;
    }

  } while (ex_num != 0);

}

void sfgets(char *_Buffer, int _MaxCount) {
  while ((getchar()) != '\n');
  fgets(_Buffer, _MaxCount, stdin);
}

void find_char(char *str, char *ch, int print_qnt) {
  int counter = 0;

  printf("Encontrei o caractere %c nas seguintes posições: ", ch[0]);

  for (int i = 0; i < strlen(str); i += 1) {
    for (int j = 0; j < strlen(ch); j += 1) {
      if (str[i] == ch[j]) {
        counter += 1;
        printf("%d; ", i);
      }
    }
  }

  if (print_qnt != 0) {
    printf("\nO caractere %c apareceu %d vezes\n", ch[0], counter);
  }

  printf("\n");
}

int is_letter(char ch) {
  if (((int)ch >= 65 && (int)ch <= 90) || ((int)ch >= 97 && (int)ch <= 122)) {
    return 1;
  }

  return 0;
}

int is_number(char ch) {
  if (((int)ch >= 48 && (int)ch <= 57)) {
    return 1;
  }

  return 0;
}

int is_alphanum(char ch) {
  if (is_letter(ch) || is_number(ch)) {
    return 1;
  }

  return 0;
}

void ex01() {
  char str[50];
  char biggest[50];
  char smallest[50];

  do {
    printf("Digite uma string, para finalizar digite 0\n> ");
    scanf("%s", str);

    if (strcmp(str, "0") != 0) {
      if (strlen(str) > strlen(biggest)) {
        strcpy(biggest, str);
      }
      if (strlen(str) <= strlen(smallest) || strlen(smallest) == 0) {
        strcpy(smallest, str);
      }
    }

  } while (strcmp(str, "0") != 0);

  printf("A maior string digitada foi %s\n A menor string digitada foi %s\n", biggest, smallest);
}

void ex02() {
  char str[50];

  printf("Digite uma string\n> ");
  scanf("%s", str);

  int counter = 0;

  for (int i = 0; i < strlen(str); i += 1) {
    if (str[i] == 'A' || str[i] == 'a') {
      counter += 1;
    }
  }
  printf("\nA letra A apareceu %d vezes\n", counter);

}

void ex03() {
  char str[50];

  printf("Digite uma string\n> ");
  scanf("%s", str);

  find_char(str, "Aa", 0);

  printf("\n");
}

void ex04() {
  char str[50];
  char ch = '\0';

  printf("Digite uma string\n> ");
  scanf("%s", str);

  printf("Digite um caractere\n> ");
  scanf(" %c", &ch);

  char chs[2] = { ch, '\0' };

  find_char(str, chs, 1);
}

void ex05() {
  char str[50];
  char ch = '\0';

  int first_time = 1;

  printf("Digite uma string\n> ");
  scanf("%s", str);

  while (is_letter(ch) == 0) {
    if (first_time != 1) {
      printf("Caractere Inválido!\n");
      first_time = 0;
    }

    printf("Digite um caractere entre A-z\n> ");
    scanf(" %c", &ch);
  }

  char chs[2] = { ch, '\0' };

  find_char(str, chs, 1);
}

void ex06() {
  char str[50];

  printf("Digite uma string\n> ");
  scanf("%s", str);

  int letter_counter = 0;
  int num_counter = 0;
  int not_alphanum_counter = 0;

  for (int i = 0; i < strlen(str); i += 1) {
    char ch = str[i];
    if (is_letter(ch) == 1) {
      letter_counter += 1;
    } else if (is_number(ch) == 1) {
      num_counter += 1;
    } else {
      not_alphanum_counter += 1;
    }
  }

  printf("Encontrei na string %d letras, %d números %d caracteres não alfanumericos\n", letter_counter, num_counter, not_alphanum_counter);

}

void ex07() {
  char str[50];

  printf("Digite uma string\n> ");
  scanf("%s", str);

  printf("A string ao contrário fica: ");

  for (int i = strlen(str); i >= 0; i -= 1) {
    printf("%c", str[i]);
  }
  printf("\n");
}

void ex08() {
  char str[50];
  char blank[50];

  printf("Digite uma string\n> ");
  sfgets(str, 50);


  int j = 0;
  for (int i = 0; i < strlen(str); i += 1) {
    if (str[i] != ' ') {
      blank[j] = str[i];
      j += 1;
    }
  }

  printf("Depois de remover os espaços a string ficou assim: %s\n", blank);
}

void ex09() {
  char str[50];

  printf("Digite uma string\n> ");
  sfgets(str, 50);

  for (int i = 0; i < strlen(str); i += 1) {
    if (str[i] == ' ') {
      for (int j = i; j < strlen(str) - 1; j += 1) {
        str[j] = str[j + 1];
      }
    }
  }

  printf("Depois de remover os espaços a string ficou assim: %s\n", str);
}

void ex10() {
  char str[50];
  char contains[3];

  printf("Digite uma string\n> ");
  scanf("%s", str);

  printf("Digite uma string de até três caracteres\n> ");
  scanf("%s", contains);


  int counter = 0;

  for (int i = 0; i < strlen(str) - strlen(contains) + 1; i += 1) {
    for (int j = 0; j < strlen(contains); j += 1) {
      if (str[i + j] != contains[j]) {
        break;
      }

      if (j == strlen(contains) - 1) {
        counter += 1;
      }
    }

  }

  printf("A string %s contém %s %d vezes\n", str, contains, counter);

}
