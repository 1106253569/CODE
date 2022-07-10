# 引入流

- 分组、查找
- 处理大量元素
- 并行

---

## 流是什么

stream是Java API新成员，以声明性方式处理数据集合

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
>  流
>
> > 需求驱动，接近事实创造
>
> 集合
>
> > 供应商驱动，即先存再用

流只能遍历一次，遍历后成这个流**被消费**了

### 迭代

分为:

1. 外部迭代(例如for-each)
2. 内部迭代(Stream使用)

> for-each属于语法糖，隐藏迭代的复杂性

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
