/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_CLIENTSOCKET_H_
#define _BGCC_CLIENTSOCKET_H_

#include <string>
#include "socket_base.h"
#include "log.h"

namespace bgcc {

    /**
	 * @class ClientSocket 
	 * @brief client socket�࣬�̳�Socket�� 
	*/
	class ClientSocket : public Socket {
	public:
        /**
		 * @brief   ���캯�������ڳ�ʼ��������IP��PORT��Ϣ
		 * @param   host   ��������ַ
		 * @param   port   �������˿�
		 * @return  ��
		 */
		ClientSocket(const std::string& host, int port) : _host(host), _port(port) {}
		~ClientSocket(){
			BGCC_NOTICE("bgcc", "Client Disconnect from %s:%d , fd=%d", 
					_host.c_str(), _port, _socket);
			close();
		}

        /**
		 * @brief   �򿪿ͻ������ӣ���Ҫ����connect����
		 * @return  �����ɹ�����0�����򷵻ش�����
		 */
        virtual int open();
        
		
        
        /**
		 * @brief   �ж�client�����Ƿ��
		 * @return  �����ɹ�����true�����򷵻�false
		 */
        virtual bool is_open() const;
    
    private:

        /**
		 * @brief   ��ȡ���ص�ַ��Դ�����ڷ������ӣ����εײ�Э�����
		 * @param   ppres   ���ط��������ĵ�ַ�б�
		 * @return  �ɹ�����0��ʧ�ܷ��ش�����
		 */
		int32_t get_address_list(struct addrinfo **ppres);
        /**
		 * @brief   ����socket��connect������
		 * @param   res  ��ַ�б�
		 * @return  �ɹ�����0��ʧ�ܷ��ش����� 
		 */
		int32_t open_impl(struct addrinfo *res);
        /**
		 * @brief   ��ȡ�����ļ�����ȡ��ʱʱ�䣬��ȡʧ�ܷ���Ĭ��ֵ
		 * @param   optname  ���򣬽���or����
		 * @return  ���س�ʱʱ��
		 */
		std::string _host;
		int32_t _port;
	};
}

#endif
