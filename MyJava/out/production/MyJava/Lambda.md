# Lambda表达式

---

## Lambda示例

--- 

1. 布尔表达式
   - `(List<String> list) -> list.isEmpty()`

2. 创建对象
   - `() -> new Apple(10)`

3. 消费一个对象
   - ` (Apple a) -> { System.out.println(a.getWeight());}`

4. 从一个对象中选择/抽取

- `(String s) -> s.length()`

5. 组合两个值
   - `(int a, int b) -> a * b`

6. 比较两个对象
   - `(Apple a1, Apple a2) -> a1.getWeight().compareTo(a2.getWeight())`

## 原始类型特化

---

Java类型分为:

1. 引用类型,例如:

> - Byte
>  - Integer
>  - Object
>  - List

2. 原始类型,例如:

> - int
>  - double
>  - byte
>  - char

**装箱与拆箱**
