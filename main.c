#include <stdio.h>
#include <stdlib.h>	
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	
	
	char nome[20];
	char resposta [4];
	int dependente;
	float salario, bruto, adiantamento, INSS, liquido1, dependente1, valor, IR, DescontoIR, liquido2;
	float alimentacao = 20.01;
	float odontoligico = 14.63;
	
	printf("\n");
	printf("DEMONSTRATIVO DE PAGAMENTO \n");
	printf("\n");
	
	printf("Nome Funcionario: ");
	scanf("%s", &nome);
	printf("Salario Base: ");
	scanf("%f", &salario);
	printf("Quantidade de dependentes: ");
	scanf("%d", &dependente);
	printf("\n");
	
	//ADIANTAMENTO
	printf("Recebe adiantamento quinzenal?[SIM/NAO]: ");
	scanf("%s", &resposta);
	
	if(!strcmp(resposta, "SIM"))
	{
		adiantamento = (salario * 40) / 100;
		printf("Valor do adiantamento R$ %.2f \n\n", adiantamento);
	}
	else
	{
		printf("Nao ha pagamento \n");
	}
	
	//INSS
	if (salario > 0 && salario <= 1100.00)
	{
		INSS = (salario * 7.5) /100;
	}
	if (salario >= 1100.01 && salario <= 2203.48)
	{
		INSS = (((salario - 1100.00) * 9) / 100 ) + 82.50;
	}
	if (salario >= 2203.49 && salario <= 3305.22)
	{
		INSS = (((salario - 2203.48) * 12) / 100 ) + 181.81;
	}
	if (salario >= 3305.23 && salario <= 6433.57)
	{
		INSS = (((salario - 3305.22) * 14) / 100 ) + 314.02; 
	}
	if (salario >= 6433.58)
	{
		INSS = 751.99;
	}
	
	printf("Desconto do INSS R$ %.2f \n", INSS);
	liquido1 = salario - INSS;
	printf("Salario liquido com o desconto do INSS R$ %.2f \n\n", liquido1);

	
	//IR
	switch (dependente)
	{
		case 1:
		valor = 189.59;
		break;
		
		case 2:
		valor = 379.18;
		break;
		
		case 3:
		valor = 568.77;
		break;
		
		case 4:
		valor = 758.36;
		break;
	}
	
		printf("Deducao por dependente R$ %.2f \n", valor);
		IR = liquido1 - valor;
		printf("Valor base para IR R$ %.2f \n", IR);
	
	if (IR <= 1903.98)
	{
		DescontoIR = 0;
	}
	if (IR >= 1903.99 && IR <= 2826.65)
	{
		DescontoIR = ((IR * 7.5) /100) - 142.80; 
	}	
	if (IR >= 2826.66 && IR <= 3751.05)
	{
		DescontoIR = ((IR * 15) /100) - 379.18; 
	}
	if (IR >= 3751.06 && IR <= 4664.68)
	{
		DescontoIR = ((IR * 22.5) /100) - 636.13; 
	}
	if (IR >= 4664.69)
	{
		DescontoIR = ((IR * 27.5) /100) - 869.36; 
	}
	
	printf("Desconto do IR R$ %.2f \n", DescontoIR);
	liquido2 = liquido1 - DescontoIR;
	printf("Salario Liquido com desconto do IR R$ %.2f \n\n", liquido2);
	
	
	return 0;
}
