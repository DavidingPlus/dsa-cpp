/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi<T> Splay<T>::insert( const T& e ) { //将关键码e插入伸展树中
   if ( !_root ) { _size = 1; return _root = new BinNode<T>( e ); } //原树为空
   BinNodePosi<T> t = search( e );
   if ( e == t->data ) return t; //目标节点t若存在，伸展至根
   if ( t->data < e ) //在右侧嫁接
      { t->parent = _root = new BinNode<T>( e, NULL, t, t->rc ); t->rc = NULL; }
   else //在左侧嫁接
      { t->parent = _root = new BinNode<T>( e, NULL, t->lc, t ); t->lc = NULL; }
   _size++; t->updateHeightAbove(); return _root; //更新规模及高度，报告插入成功
} //无论e是否存在于原树中，返回时总有_root->data == e
