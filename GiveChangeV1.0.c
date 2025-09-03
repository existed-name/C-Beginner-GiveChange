/* 
    这至少是第4个版本了
    以前做得比较零碎,这个版本第一次整合了较多的玩法,当然,有待更新,并且随着所学知识的增加,还会进一步优化,比如推翻重建
    这应该算我第一个严格意义上的小游戏,我从其中收获了很多乐趣,也培养了自己的编程能力,更多地,是对做出更"好玩"的项目的向往
*/
#include <stdio.h>
int main()
{  //介绍项目  
   int price=0;
   int bill=0;
   printf("找零计算器！\n");
   printf("请输入顾客所购各个商品价格（元）,由计算器算总账,当输入一个负数时停止记账并输出账目：\n");
   //记账
    while(price>=0){
   	    scanf("%d",&price);
   	    bill+=price;
   } 
   
    bill-=price;
   
    printf("账单金额为%d元\n",bill);
   //算找零
    int amount;
	out:printf("请输入顾客支付金额(元):\n");
    scanf("%d",&amount);
    int change=amount-bill;
    if(amount==0){
		printf("打咩，今天不能白嫖！\n");
		printf("请重新支付！\n");
		goto out;
	}
    else{
   //没交够钱
        if(change<0){
		     printf("真不巧，还差%d元\n",-change);
		     printf("请补交%d元\n",-change);
		     int repay=0;
		     do{
		 	   int pay;
			   scanf("%d",&pay);
			   repay+=pay;
			   if(repay<-change){
				   printf("还差%d元,请补交！\n",repay+change);
			   }
			   else{
				   printf("好啦，你交够了！\n");
			   }
		   } while(repay<-change);
		
		   if(repay>-change){
			   printf("找你%d元",repay+change);
		  }   
	   }
	//交够钱
	   else{
		   if(change==0){
			   printf("刚刚好！");
		   }
		   else{
			   printf("找你%d元",change);
		   }
	   }	
    }
    
    printf("谢谢惠顾，欢迎下次光临！");
	return 0;
}
