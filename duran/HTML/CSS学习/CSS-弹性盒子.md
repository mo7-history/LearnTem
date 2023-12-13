# 弹性盒子

为了解决以下布局需求

- 在父内容里面垂直居中一个块内容。
- 使容器的所有子项占用等量的可用宽度/高度，而不管有多少宽度/高度可用。
- 使多列布局中的所有列采用相同的高度，即使它们包含的内容量不同。

## 说明

当元素变现为flex框时，沿着两个轴来布局：
![picture](./../../图片/HTML/CSS图片/弹性盒子.png)

- 主轴（main axis）是沿着 flex 元素放置的方向延伸的轴（比如页面上的横向的行、纵向的列）。该轴的开始和结束被称为 main start 和 main end。
- 交叉轴（cross axis）是垂直于 flex 元素放置方向的轴。该轴的开始和结束被称为 cross start 和 cross end。
- 设置了 display: flex 的父元素被称之为 flex 容器（flex container）。
- 在 flex 容器中表现为弹性的盒子的元素被称之为 flex 项（flex item）.

## 属性

### flex

### flex-direction

指定了弹性子元素在父容器中的位置
它可以指定主轴的方向（弹性盒子子类放置的地方）——它默认值是 row，这使得它们在按你浏览器的默认语言方向排成一排（在英语/中文浏览器中是从左到右）。

- row：横向从左到右排列（左对齐），默认的排列方式。
- row-reverse：反转横向排列（右对齐，从后往前排，最后一项排在最前面
- column：纵向排列。
- column-reverse：反转纵向排列，从后往前排，最后一项排在最上面。

### flex-wrap

用于指定弹性盒子的子元素换行方式。
值：

- nowrap - 默认， 弹性容器为单行。该情况下弹性子项可能会溢出容器。
- wrap - 弹性容器为多行。该情况下弹性子项溢出的部分会被放置到新行，子项内部会发生断行
- wrap-reverse -反转 wrap 排列。

### flex-flow

是flex-direction和flex-wrap的缩写

```css
flex-direction: row;
flex-wrap: wrap;
//替换为
flex-flow: row wrap;
```

### align-content

用于修改 flex-wrap 属性的行为。类似于 align-items, 但它不是设置弹性子元素的对齐，而是设置各个行的对齐。

- stretch - 默认。各行将会伸展以占用剩余的空间。
- flex-start - 各行向弹性盒容器的起始位置堆叠。
- flex-end - 各行向弹性盒容器的结束位置堆叠。
- center -各行向弹性盒容器的中间位置堆叠。
- space-between -各行在弹性盒容器中平均分布。
- space-around - 各行在弹性盒容器中平均分布，两端保留子元素与子元素之间间距大小的一半。

### 水平和垂直对齐

使用弹性盒子的功能让 flex 项沿主轴或交叉轴对齐

```css
div {
  display: flex;
  align-items: center;//控制flex项在交叉轴上的位置
  justify-content: space-around;//
}
```

1. align-items 控制flex项在交叉轴上的位置
   - 默认的值是 stretch，其会使所有 flex 项沿着交叉轴的方向拉伸以填充父容器。如果父容器在交叉轴方向上没有固定宽度（即高度），则所有 flex 项将变得与最长的 flex 项一样长（即高度保持一致）。我们的第一个例子在默认情况下得到相等的高度的列的原因。
   - 也可以设置诸如 flex-start 或 flex-end 这样使 flex 项在交叉轴的开始或结束处对齐所有的值
   - center 值会使这些项保持其原有的高度，但是会在交叉轴居中。这就是那些按钮垂直居中的原因。
2. justify-content 控制 flex 项在主轴上的位置
   - 默认值是 flex-start，这会使所有 flex 项都位于主轴的开始处。
   - 也可以用 flex-end 来让 flex 项到结尾处。
   - center 在 justify-content 里也是可用的，可以让 flex 项在主轴居中
   - 上面用到的值 space-around 是很有用的——它会使所有 flex 项沿着主轴均匀地分布，在任意一端都会留有一点空间。
   - 还有一个值是 space-between，它和 space-around 非常相似，只是它不会在两端留下任何空间。

## 弹性子元素属性

### 排序

order：

- 设置弹性容器内弹性子元素的属性
- 用整数值来定义排列顺序，数值小的排在前面。可以为负值。
- order 值大的 flex 项比 order 值小的在显示顺序中更靠后。
- 相同 order 值的 flex 项按源顺序显示。所以假如你有四个元素，其 order 值分别是 2，1，1 和 0，那么它们的显示顺序就分别是第四，第二，第三，和第一。

### 对齐

设置"margin"值为"auto"值，自动获取弹性容器中剩余的空间。所以设置垂直方向margin值为"auto"，可以使弹性子元素在弹性容器的两上轴方向都完全居中。

### align-self

align-self会覆盖 align-items 的行为
align-self 属性不适用于块类型的盒模型和表格单元。如果任何 flexbox 元素的侧轴方向 margin 值设置为 auto，则会忽略 align-self。

- auto：如果'align-self'的值为'auto'，则其计算值为元素的父元素的'align-items'值，如果其没有父元素，则计算值为'stretch'。
- flex-start：弹性盒子元素的侧轴（纵轴）起始位置的边界紧靠住该行的侧轴起始边界。
- flex-end：弹性盒子元素的侧轴（纵轴）起始位置的边界紧靠住该行的侧轴结束边界。
- center：弹性盒子元素在该行的侧轴（纵轴）上居中放置。（如果该行的尺寸小于弹性盒子元素的尺寸，则会向两个方向溢出相同的长度）。
- baseline：如弹性盒子元素的行内轴与侧轴为同一条，则该值与'flex-start'等效。其它情况下，该值将参与基线对齐。
- stretch：如果指定侧轴大小的属性值为'auto'，则其值会使项目的边距盒的尺寸尽可能接近所在行的尺寸，但同时会遵照'min/max-width/height'属性的限制。

### flex属性

属性用于指定弹性子元素如何分配空间。

- auto: 计算值为 1 1 auto
- initial: 计算值为 0 1 auto
- none：计算值为 0 0 auto
- inherit：从父元素继承
- [ flex-grow ]：定义弹性盒子元素的扩展比率。
- [ flex-shrink ]：定义弹性盒子元素的收缩比率。
- [ flex-basis ]：定义弹性盒子元素的默认基准值。