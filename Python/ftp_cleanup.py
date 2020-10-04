import time
import ftputil
import logging

logging.basicConfig(filename='ftpLog.txt',level=logging.DEBUG, format=' %(asctime)s - %(levelname)s - %(message)s')
logging.info('start program')

ftp_user = 'username here'
ftp_pass = 'password here'
ftp_server = 'ip or dns here'

host = ftputil.FTPHost(ftp_server,ftp_user,ftp_pass)
my_ftppath = '/Export/Daily'
now = time.time()
host.chdir(my_ftppath)
names = host.listdir(host.curdir)
for name in names:
    if host.path.getmtime(name) < (now - (1 * 86400)):
        if host.path.isdir(name):
            host.rmtree(name, ignore_errors=False, onerror=StopIteration)
            print('Directory: '+my_ftppath+'/'+name+' is removed from the ftp server')
            #log this in the txt file
            logging.info('Directory: ' + my_ftppath + '/' + name + ' is removed from the ftp server')
        else:
            logging.debug('Nothing to do')
logging.info('ftp connection closed')
host.close()

    