#!/usr/bin/python
import sys,os,re,logging,shutil
import optparse

def setDir(folder):
    if folder not in os.listdir('./'):
        os.mkdir(folder)
    else:
        shutil.rmtree(folder)
        os.mkdir(folder)

def main( module = '__main__', **kwargs ):
	# parse command line
	parser = optparse.OptionParser()
	parser.add_option("-t", "--platform", type="string", dest="platformName", metavar="PLATFORM")
	options, args = parser.parse_args()
	platform_name = options.platformName
	cmakeGenerator = 'Visual Studio 14 2015 Win64'
	
	
	if(platform_name == 'win64-vs14'):
		# make proj dir
		proj_folder = "server.vsproj"
		setDir(proj_folder)
		os.chdir(proj_folder)

		# Generate proj
		os.system('cmake ../ -G "%s" -DCMAKE_PLATFORM:STRING="%s"' % (cmakeGenerator, platform_name))

		setDir("Debug")
		
	elif(platform_name == 'osx'):
		pass
	
if __name__ == '__main__':
    main()


