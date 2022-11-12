/*
 *      gettextpd.h
 *      Main file for GettextPD
 *
 *      c Copyright 2009 Compdigitec. All rights reserved.
 *
 *      Copying and distribution of this file, with or without modification,
 *      are permitted in any medium without royalty provided the copyright
 *      notice and this notice are preserved.  This file is offered as-is,
 *      without any warranty.
 */
#ifndef __GETTEXTPD__
#define __GETTEXTPD__

#include <vector>
#include <map>
#include <string>
#include <algorithm>


#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

typedef vector<string> VS;

// gettext functions
char* gettext (char *msgid);
std::string gettext (std::string msgid);
char* textdomain (const char *domain_name);
char* bindtextdomain (const char *domain_name, const char *dir_name);
char* setlocale (int category, const char* locale);

long getstr();

// macros
#define _(str) gettext(str)

// globals
std::string gtpd_locale = "";
std::string gtpd_domain = "";
std::string gtpd_location = "";

bool readFlag = false;
typedef map<std::string, std::string> MAPSS;
MAPSS mp;

// function bodies
char* gettext(char* msgid)
{
	if(gtpd_locale == "en")
	{
		return(msgid);
	}

	if(readFlag == false)
	{
		getstr();
	}

	if(mp.size() == 0)
	{
		return msgid;
	}

	std::string x(msgid);
	std::string result;

	result = gettext(x);

	if(result == x)
	{
		return msgid;
	}

	char* nb = (char*)malloc(sizeof(char)*result.length() * 2 + 2);
	strcpy(nb,result.c_str());
	return nb;
}

std::string gettext(std::string msgid)
{
	if(gtpd_locale == "en")
	{
		return(msgid);
	}

	if(readFlag == false)
	{
		getstr();
	}

	if(mp.size() == 0)
	{
		return msgid;
	}


	string msgid2 = msgid;
	std::transform(msgid2.begin(), msgid2.end(), msgid2.begin(), ::toupper);

	MAPSS::iterator itr = mp.find(msgid2);
	if( itr != mp.end() )
	{
		return mp[msgid2]; //ê›íËÇ≥ÇÍÇƒÇ¢ÇÈèÍçáÇÃèàóù
	}
	else
	{
		return msgid;  //ê›íËÇ≥ÇÍÇƒÇ¢Ç»Ç¢èÍçáÇÃèàóù
	}
}

//std::string gettext(std::string msgid)
//{
//	std::string path = gtpd_location + "/" + gtpd_locale + "/LC_MESSAGES/" + gtpd_domain + ".mo";
//	std::ifstream stream;
//	stream.open(path.c_str());
//	std::string resultline;
//	while(!stream.eof()) {
//		getline(stream,resultline);
//		if(strstr(resultline.c_str(),msgid.c_str()) != NULL) {
//			break;
//		}
//		resultline = "";
//	}
//	if(resultline == "") {
//		// not found
//		return msgid;
//	}
//	int splitloc = resultline.find("\t");
//	return resultline.substr(splitloc+1);
//}

long getstr_mo()
{
	char buff[1000];

	if(gtpd_locale == "en")
	{
		return(-1);
	}
	std::string path = gtpd_location + "\\locale\\" + gtpd_locale + "\\LC_MESSAGES\\" + gtpd_domain + ".po";

	mp.clear();
	readFlag = true;

	FILE *fpin = fopen(path.c_str(),"rt");
	if(fpin == NULL)
	{
		return(-1);
	}
	else
	{
		while(NULL != fgets(buff,1000,fpin))
		{
			if(strstr(buff,"msgid") != NULL)
			{
				VS vs1 = split(buff, "\"");

				fgets(buff,1000,fpin);

				if(strstr(buff,"msgstr") == NULL)
				{
					printf("Structure fairure.\n");
					goto JUMP1;
				}

				VS vs2 = split(buff, "\"");
				mp[vs1[1]] = vs2[1];
			}
	JUMP1:
		}

		fclose(fpin);

		return(mp.size());
	}
}

long getstr()
{
	char buff[1000];

	if(gtpd_locale == "en")
	{
		return(-1);
	}

	std::string path = gtpd_location + "\\locale\\" + gtpd_locale + "\\LC_MESSAGES\\" + gtpd_domain + ".csv";

	mp.clear();
	readFlag = true;

	FILE *fpin = fopen(path.c_str(),"rt");
	if(fpin == NULL)
	{
		return(-1);
	}
	else
	{
		while(NULL != fgets(buff,1000,fpin))
		{
			VS vs = split(buff, ",");
			std::transform(vs[1].begin(), vs[1].end(), vs[1].begin(), ::toupper);
			mp[vs[1]] = vs[2];
		}

		fclose(fpin);

		return(mp.size());
	}
}

long GetStrFromCsv(string sCsvName, int iFlag)
{
	char buff[1000];

	if(gtpd_locale == "en")
	{
		return(-1);
	}
	std::string path = gtpd_location + "\\locale\\" + gtpd_locale + "\\LC_MESSAGES\\" + sCsvName;

	if(iFlag == 1)
	{
		mp.clear();
	
	}
	
	readFlag = true;

	FILE *fpin = fopen(path.c_str(),"rt");
	fgets(buff,1000,fpin);
	if(fpin == NULL)
	{
		return(-1);
	}
	else
	{
		while(NULL != fgets(buff,1000,fpin))
		{
			VS vs = split(buff, ",");
			mp[vs[1]] = vs[2];
		}

		fclose(fpin);

		return(mp.size());
	}
}

char* textdomain(const char *domain_name)
{
	gtpd_domain = domain_name;
	char* res = (char*)malloc(sizeof(char)*100);
	strcpy(res,domain_name);
	return res;
}

char* bindtextdomain (const char *domain_name, const char *dir_name)
{
    gtpd_location = dir_name;
    textdomain(domain_name);
    char* res = (char*)malloc(sizeof(char)*100);
    strcpy(res,dir_name);
    return res;
}

char* setlocale_iwa (int category, const char* locale)
{
    gtpd_locale = locale;
    char* res = (char*)malloc(sizeof(char)*100);
    strcpy(res,locale);
    return res;
}

std::vector<std::string> split(std::string str, std::string delim) {
  std::vector<std::string> items;
  std::size_t dlm_idx;
  if(str.npos == (dlm_idx = str.find_first_of(delim))) {
    items.push_back(str.substr(0, dlm_idx));
  }
  while(str.npos != (dlm_idx = str.find_first_of(delim))) {
    if(str.npos == str.find_first_not_of(delim)) {
      break;
    }
    items.push_back(str.substr(0, dlm_idx));
    dlm_idx++;
    str = str.erase(0, dlm_idx);
    if(str.npos == str.find_first_of(delim) && "" != str) {
      items.push_back(str);
      break;
    }
  }
  return items;
}
 
#endif

//folder/fr_FR/LC_MESSAGES/hello.mo
// test.cpp
/*
#include "gettextpd.h"
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    setlocale( LC_ALL, "fr_FR" );
    bindtextdomain( "hello", "." );
    textdomain( "hello" );
    std::cout << gettext("Hello, world!") << "\n";
    std::cout << _("THis is A TeST StriNg") << "\n";
    exit(0);
}
*/