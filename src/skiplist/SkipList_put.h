/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2024.
 ******************************************************************************************/

#pragma once

template <typename K, typename V> bool Skiplist<K, V>::put( K k, V v ) { //跳转表词条插入算法
   Entry<K, V> e = Entry<K, V>( k, v ); //待插入的词条（将被同一塔中所有节点共用）
   QNodePosi< Entry<K, V> > p = search( k ); //查找插入位置：新塔将紧邻其右，逐层生长
   ListNodePosi< Quadlist< Entry<K, V> >* > qlist = last(); //首先在最底层
   QNodePosi< Entry<K, V> > b = qlist->data->insert( e, p ); //创建新塔的基座
   while ( rand() & 1 ) { //经投掷硬币，若确定新塔需要再长高，则
      while ( p->pred && !p->above ) p = p->pred; //找出不低于此高度的最近前驱
      if ( !p->pred && !p->above ) { //若该前驱是head，且已是最顶层，则
         insertFirst( new Quadlist< Entry<K, V> > ); //需要创建新的一层
         first()->data->head->below = qlist->data->head;
         qlist->data->head->above = first()->data->head;
      }
      p = p->above; qlist = qlist->pred; //上升一层，并在该层
      b = qlist->data->insert( e, p, b ); //将新节点插入p之后、b之上
   } //课后：调整随机参数，观察总体层高的相应变化
   return true; //Dictionary允许元素相等，插入必成功
} //体会：得益于哨兵的设置，哪些环节被简化了？