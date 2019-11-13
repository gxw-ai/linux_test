#include<linux/module.h>  
#include<linux/list.h>
#include<linux/slab.h>
struct my_list
{
	int num;
	struct list_head list_node;
};

static int __init jun_init(void)
{
	
	printk(KERN_ALERT"Hello there,I'm jun,and welcome to my blog Dreambegin\n");
	struct list_head *list_h = NULL;
	list_h = (struct list_head *)kmalloc(sizeof(struct list_head),GFP_KERNEL);//若不分派内存，则进程被kill，因为没给链表的头指针分派内存
	INIT_LIST_HEAD(list_h);
	struct my_list fir_list =//方法一：初始化
	{
		.num = 1,
		.list_node = LIST_HEAD_INIT(fir_list.list_node)
	};
	
/*	struct my_list fir_list;//方法二：初始化
	fir_list.num = 1;
	INIT_LIST_HEAD(&fir_list.list_node);*/
	list_add(&fir_list.list_node,list_h);
	struct my_list sec_list =
	{
		.num = 2,
		.list_node = LIST_HEAD_INIT(sec_list.list_node)
	};
	/*struct my_list sec_list;
	sec_list.num = 2;
	INIT_LIST_HEAD(&sec_list.list_node);*/
	list_add(&sec_list.list_node,list_h);

	struct my_list *tmp_list = NULL;
	list_for_each_entry(tmp_list,list_h,list_node)
	{
		printk(KERN_INFO"node:%d\n",tmp_list->num);
		//printk("node:%d\n",tmp_list->num);//最好带打印级别
	}
	kfree(list_h);
	return 0;
}

static void __exit jun_exit(void)
{
	printk(KERN_ALERT"Goodbye,nice to see you.\n");
}

module_init(jun_init);
module_exit(jun_exit);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("gxw");
