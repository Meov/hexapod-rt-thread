#ifndef _CAN_H
#define _CAN_H
#include "rtdef.h"


#define CAN_DEV_NAME       "can1"      /* CAN �豸���� */

struct rt_can_msg
{
    rt_uint32_t id  : 29;   /* CAN ID, ��־��ʽ 11 λ����չ��ʽ 29 λ */
    rt_uint32_t ide : 1;    /* ��չ֡��ʶλ */
    rt_uint32_t rtr : 1;    /* Զ��֡��ʶλ */
    rt_uint32_t rsv : 1;    /* ����λ */
    rt_uint32_t len : 8;    /* ���ݶγ��� */
    rt_uint32_t priv : 8;   /* ���ķ������ȼ� */
    rt_uint32_t hdr : 8;    /* Ӳ�����˱�� */
    rt_uint32_t reserved : 8;
    rt_uint8_t data[8];     /* ���ݶ� */
};

struct rt_can_filter_item
{
    rt_uint32_t id  : 29;   /* ���� ID */
    rt_uint32_t ide : 1;    /* ��չ֡��ʶλ */
    rt_uint32_t rtr : 1;    /* Զ��֡��ʶλ */
    rt_uint32_t mode : 1;   /* ���˱�ģʽ */
    rt_uint32_t mask;       /* ID ���룬0 ��ʾ��Ӧ��λ�����ģ�1 ��ʾ��Ӧ��λ����ƥ�� */
    rt_int32_t hdr;         /* -1 ��ʾ��ָ�����˱�ţ���Ӧ�Ĺ��˱���ƿ�Ҳ���ᱻ��ʼ��������Ϊ���˱�ţ���Ӧ�Ĺ��˱���ƿ�ᱻ��ʼ�� */
#ifdef RT_CAN_USING_HDR
    /* ���˱�ص����� */
    rt_err_t (*ind)(rt_device_t dev, void *args , rt_int32_t hdr, rt_size_t size);
    /* �ص��������� */
    void *args;
#endif /*RT_CAN_USING_HDR*/
};


struct rt_can_filter_config
{
    rt_uint32_t count;                  /* ���˱����� */
    rt_uint32_t actived;                /* ���˱���ѡ�1 ��ʾ��ʼ�����˱���ƿ飬0 ��ʾȥ��ʼ�����˱���ƿ� */
    struct rt_can_filter_item *items;   /* ���˱�ָ�룬��ָ��һ�����˱����� */
};


#endif