/* 找零游戏V1.1 */
//自从上次更新以来有2个月了...
//本次在V.C.1.0代码基础上进行了以下更新:
//1. 更新了顾客第一次付钱为负数的应对方法
//2. 更新了顾客没交够钱的应对方法
//3. 更新了一些输出语句以及解决了一些小问题
//4. 美化代码,并将所有中文输入法的标点改为英文输入法

#include <stdio.h>
int main()
{   //介绍项目  
    int price=0;
    int bill=0;
    printf("找零游戏!\n");
    printf("游戏规则如下:\n");
 	printf("输入顾客(你)所购各个商品价格(RMB),由计算器算账,当输入一个负数时停止记账并输出账单金额:\n");
 	printf("得到账单总额后,任意输入一个整数表示你付的钱\n");
 	printf("开始输入吧\n");
    //记账
    while ( price >= 0 ){
   		scanf("%d", &price);
   	    bill += price;
	} 
   
    bill -= price;
   
    printf("收银员:\"一共%d元\" \n", bill);
    //算找零
    int amount;
	out:printf("字幕:输入你支付的金额(元):\n");
    scanf("%d", &amount);
    int change = amount - bill;
    if ( amount == 0 ){
		printf("收银员:\"亲,本店不支持白嫖~\"\n");
		printf("字幕:真香(bushi)~重新支付!\n");
		goto out;
	}
	else if ( amount < 0 ){
		printf("收银员:\"你见过面额为负数的￥吗?\"\n");
		printf("字幕:别搞,重新支付!\n");
		goto out;
	}
    else{
    //没交够钱
        if ( change < 0 ){
		    printf("收银员:\"真不巧，还差%d元\"\n", -change);
		    printf("收银员:\"请补交%d元\"\n", -change);
		    
		    int repay = 0;
		    do{
				int pay;
				scanf("%d", &pay);
			    repay += pay;
			    if ( pay == 0 ){
					printf("收银员:\"想赖账是吧~\"\n");
					printf("字幕:拒绝老赖,重新支付!\n");
				}
				else if ( pay < 0 ){
						printf("收银员:\"搞我心态?\"\n");
						printf("字幕:有脾气?重新支付就好了!\n");
				}
			    else if ( repay < -change ){
						printf("收银员:\"亲还差%d元~\"\n", - ( repay + change ) );
			    }
			    else{
				    printf("收银员:\"终于交够了~\"\n");
			   	}
		    } 
			while ( repay < -change );
		
		   	if ( repay > -change ){
			 	printf("收银员:\"找你%d元\"\n", repay + change);
		  	}   
	    }
	//交够钱
	    else{
		    if ( change == 0 ){
			    printf("收银员:\"刚刚好!\"\n");
		    }
		    else{
			    printf("收银员:\"找你%d元~\"\n", change);
		    }
	    }	
	}
    
    printf("收银员:\"亲下次再来~\"\n");
	return 0;
}
