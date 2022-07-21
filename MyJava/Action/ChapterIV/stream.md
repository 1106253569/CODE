# 引入流

- 分组、查找
- 处理大量元素
- 并行

---

## 流是什么

stream 是 Java API 新成员，以声明性方式处理数据集合

> 通过查询语句来表达，而不是临时编写一个实现

## 流与集合

> 差异在于计算时机

- 集合

  - 每个元素都得先算出才可添加到集合

- 流

  - 元素按需计算

---

> 管理学类比
>
> 流
>
> > 需求驱动，接近事实创造
>
> 集合
>
> > 供应商驱动，即先存再用

流只能遍历一次，遍历后成这个流**被消费**了

### 迭代

分为:

1. 外部迭代(例如 for-each)
2. 内部迭代(Stream 使用)

> for-each 属于语法糖，隐藏迭代的复杂性

```
List<String> names=new ArrayList<>();
//利用for-each外部迭代
for(Dish d:menu)
    names.add(d.getName());

//利用迭代器外部迭代
Iterator<Dish> iterator= (Iterator<Dish>) menu.iterator();
while (iterator.hasNext()){
    Dish d=iterator.next();
    names.add(d.getName());
}

//利用stream内部迭代
List<String> name1= menu.stream().map(Dish::getName).toList();
```

## 流操作

`List<String> name1 = menu.stream().map(Dish::getName).toList();`

两类操作:

1. map()等可以连成一条流水线
2. collect(Collectors.toList())触发流水线执行并关闭它

- 1 类这种可连接起来的流操作称为**中间操作**
- 关闭流的操作操作称为**终端操作**

> 例如 filter 和 sorted**中间操作**返回另一个流
>
> 终端操作会在流的流水线生成结果，为任何不是流的值
>
> > List、Integer 甚至 void

### 流的使用

**包括：**

1. 数据源(如集合)
2. 中间操作链
3. 终端操作
