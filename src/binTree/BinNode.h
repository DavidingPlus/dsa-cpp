/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

using Rank = unsigned int;

#if defined( DSA_REDBLACK ) //在红黑树中
#define stature( p ) ( ( p ) ? ( p )->height : 0 ) //外部节点（黑）高度为0，以上递推
#else //其余BST中
#define stature( p ) ( (int)( ( p ) ? ( p )->height : -1 ) ) //外部节点高度为-1，以上递推
#endif

typedef enum { RB_RED, RB_BLACK} RBColor; //节点颜色

template <typename T> struct BinNode;
template <typename T> using BinNodePosi = BinNode<T>*; //节点位置

template <typename T> struct BinNode { //二叉树节点模板类
// 成员（为简化描述起见统一开放，读者可根据需要进一步封装）
   T data; //数值
   BinNodePosi<T> parent, lc, rc; //父节点及左、右孩子
   Rank height; //高度（通用）
   Rank npl; //Null Path Length（左式堆，也可直接用height代替）
   RBColor color; //颜色（红黑树）
// 构造方法
   BinNode() : parent( NULL ), lc( NULL ), rc( NULL ), height( 0 ), npl( 1 ), color( RB_RED ) {}
   BinNode( T e, BinNodePosi<T> p = NULL, BinNodePosi<T> lc = NULL,
            BinNodePosi<T> rc = NULL, int h = 0, int l = 1, RBColor c = RB_RED )
      : data( e ), parent( p ), lc( lc ), rc( rc ), height( h ), npl( l ), color( c )
      { if (lc) lc->parent = this; if (rc) rc->parent = this; }
// 操作接口
   Rank size(); //统计当前节点后代总数，亦即以其为根的子树的规模
   Rank updateHeight(); //更新当前节点高度
   void updateHeightAbove(); //更新当前节点及其祖先的高度
   BinNodePosi<T> insertLc( T const& ); //插入左孩子
   BinNodePosi<T> insertRc( T const& ); //插入右孩子
   void attachLc( BinNodePosi<T> ); //接入左子树
   void attachRc( BinNodePosi<T> ); //接入右子树
   BinNodePosi<T> succ(); //取当前节点的直接后继
   template <typename VST> void travLevel( VST& ); //子树层次遍历
   template <typename VST> void travPre( VST& ); //子树先序遍历
   template <typename VST> void travIn( VST& ); //子树中序遍历
   template <typename VST> void travPost( VST& ); //子树后序遍历
   /*DSA*/ template <typename VST> void traverse( VST& ); //自定义遍历
// 比较器、判等器（各列其一，其余自行补充）
   bool operator< ( BinNode const& bn ) { return data < bn.data; } //小于
   bool operator== ( BinNode const& bn ) { return data == bn.data; } //等于
   /*DSA*/
   /*DSA*/BinNodePosi<T> zig(); //顺时针旋转
   /*DSA*/BinNodePosi<T> zag(); //逆时针旋转
   /*DSA*/BinNodePosi<T> balance(); //完全平衡化
   /*DSA*/BinNodePosi<T> imitate( const BinNodePosi<T> ); //临摹
};

#include "BinNode_implementation.h"