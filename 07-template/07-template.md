第七章主要围绕着模板展开，下面是记录的一些知识点


# 概念
Concepts是C++20新增的特性，它是一个谓词，用于约束模板的类型参数应该具有的属性。  
如 概念 Comparable T ，说明模板的类型参数 应该是可比较的。
## 概念的构建方法
~~~cpp
template<typename T>
concept Comparable = requires(T a, T b){
{a < b} -> std::convertiable_to(bool)
};
~~~

## 使用概念约束模板
~~~cpp
template<Comparable T>
void compare(T a, T b)
{
  if(a < b)
	std::cout<<"a<b\n";
  else
	std::cout<<"a>b\n";
}
~~~

## 使用被概念约束的模板函数
~~~cpp
int main()
{
	int a=1, b=2;
	compare(a, b);
}
~~~
以上就是概念的内容。


