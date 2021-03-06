//
// mime_types.cpp
// ~~~~~~~~~~~~~~
//header('Content-Type: text/event-stream');
//header('Cache-Control: no-cache');
//

#include "mime_types.hpp"
#include <string>
#include <boost/algorithm/string.hpp>
extern void freshregx();
namespace http {
namespace server {
namespace mime_types {

struct mapping
{
	const char* extension;
	const char* mime_type;
} mappings[] =
{
	{"*","application/octet-stream"},
	{"323","text/h323"},
	{"action","text/html"},
	{"acx","application/internet-property-stream"},
	{"ai","application/postscript"},
	{"aif","audio/x-aiff"},
	{"aifc","audio/x-aiff"},
	{"aiff","audio/x-aiff"},
	{"asf","video/x-ms-asf"},
	{"asp","text/html"},
	{"asr","video/x-ms-asf"},
	{"asx","video/x-ms-asf"},
	{"au","audio/basic"},
	{"avi","video/x-msvideo"},
	{"axs","application/olescript"},
	{"bas","text/plain"},
	{"bcpio","application/x-bcpio"},
	{"bin","application/octet-stream"},
	{"bmp","image/bmp"},
	{"c","text/plain"},
	{"cat","application/vnd.ms-pkiseccat"},
	{"call","text/html"},
	{"cdf","application/x-cdf"},
	{"cer","application/x-x509-ca-cert"},
	{"class","application/octet-stream"},
	{"clp","application/x-msclip"},
	{"cmd","text/html"},
	{"cmx","image/x-cmx"},
	{"cod","image/cis-cod"},
	{"cpio","application/x-cpio"},
	{"crd","application/x-mscardfile"},
	{"crl","application/pkix-crl"},
	{"crt","application/x-x509-ca-cert"},
	{"csh","application/x-csh"},
	{"css","text/css"},
	{"csp","text/html"},
	{"dcr","application/x-director"},
	{"der","application/x-x509-ca-cert"},
	{"dir","application/x-director"},
	{"dll","application/x-msdownload"},
	{"dms","application/octet-stream"},
	{"doc","application/msword"},
	{"dot","application/msword"},
	{"dvi","application/x-dvi"},
	{"dxr","application/x-director"},
	{"eps","application/postscript"},
	{"etx","text/x-setext"},
	{"evy","application/envoy"},
	{"exe","application/octet-stream"},
	{"fif","application/fractals"},
	{"flr","x-world/x-vrml"},
	{"flv","video/x-flv"},
	{"gif","image/gif"},
	{"gtar","application/x-gtar"},
	{"gz","application/x-gzip"},
	{"h","text/plain"},
	{"hdf","application/x-hdf"},
	{"hlp","application/winhlp"},
	{"hqx","application/mac-binhex40"},
	{"hta","application/hta"},
	{"htc","text/x-component"},
	{"htm","text/html"},
	{"html","text/html"},
	{"htt","text/webviewhtml"},
	{"ico","image/x-icon"},
	{"ief","image/ief"},
	{"iii","application/x-iphone"},
	{"ins","application/x-internet-signup"},
	{"isp","application/x-internet-signup"},
	{"jfif","image/pipeg"},
	{"jpe","image/jpeg"},
	{"jpeg","image/jpeg"},
	{"jpg","image/jpeg"},
	{"js","application/x-javascript"},
	{"json","application/json"},
	{"jsp","text/html"},
	{"latex","application/x-latex"},
	{"lha","application/octet-stream"},
	{"lsf","video/x-la-asf"},
	{"lsx","video/x-la-asf"},
	{"lzh","application/octet-stream"},
	{"m13","application/x-msmediaview"},
	{"m14","application/x-msmediaview"},
	{"m3u","audio/x-mpegurl"},
	{"man","application/x-troff-man"},
	{"mdb","application/x-msaccess"},
	{"me","application/x-troff-me"},
	{"mht","message/rfc822"},
	{"mhtml","message/rfc822"},
	{"mid","audio/mid"},
	{"mny","application/x-msmoney"},
	{"mov","video/quicktime"},
	{"movie","video/x-sgi-movie"},
	{"mobile","text/html"},
	{"mp2","video/mpeg"},
	{"mp3","audio/mpeg"},
	{"mp4","video/mp4"},
	{"mpa","video/mpeg"},
	{"mpe","video/mpeg"},
	{"mpeg","video/mpeg"},
	{"mpg","video/mpeg"},
	{"mpp","application/vnd.ms-project"},
	{"mpv2","video/mpeg"},
	{"ms","application/x-troff-ms"},
	{"mvb","application/x-msmediaview"},
	{"nws","message/rfc822"},
	{"oda","application/oda"},
	{"ola","text/html"},
	{"p10","application/pkcs10"},
	{"p12","application/x-pkcs12"},
	{"p7b","application/x-pkcs7-certificates"},
	{"p7c","application/x-pkcs7-mime"},
	{"p7m","application/x-pkcs7-mime"},
	{"p7r","application/x-pkcs7-certreqresp"},
	{"p7s","application/x-pkcs7-signature"},
	{"pbm","image/x-portable-bitmap"},
	{"pdf","application/pdf"},
	{"pfx","application/x-pkcs12"},
	{"pgm","image/x-portable-graymap"},
	{"php","text/html"},
	{"pko","application/ynd.ms-pkipko"},
	{"pma","application/x-perfmon"},
	{"pmc","application/x-perfmon"},
	{"pml","application/x-perfmon"},
	{"pmr","application/x-perfmon"},
	{"pmw","application/x-perfmon"},
	{"png","image/png"},
	{"pnm","image/x-portable-anymap"},
	{"pot,","application/vnd.ms-powerpoint"},
	{"ppm","image/x-portable-pixmap"},
	{"pps","application/vnd.ms-powerpoint"},
	{"ppt","application/vnd.ms-powerpoint"},
	{"prf","application/pics-rules"},
	{"ps","application/postscript"},
	{"pub","application/x-mspublisher"},
	{"qt","video/quicktime"},
	{"ra","audio/x-pn-realaudio"},
	{"ram","audio/x-pn-realaudio"},
	{"rar","application/x-rar-compressed"},
	{"ras","image/x-cmu-raster"},
	{"regex","text/html"},
	{"rgb","image/x-rgb"},
	{"rmi","audio/mid"},
	{"rmvb","application/vnd.rn-realmedia-vbr"},
	{"roff","application/x-troff"},
	{"rtf","application/rtf"},
	{"rtx","text/richtext"},
	{"scd","application/x-msschedule"},
	{"sct","text/scriptlet"},
	{"setpay","application/set-payment-initiation"},
	{"setreg","application/set-registration-initiation"},
	{"sh","application/x-sh"},
	{"shar","application/x-shar"},
	{"sit","application/x-stuffit"},
	{"snd","audio/basic"},
	{"solr","text/html"},
	{"spc","application/x-pkcs7-certificates"},
	{"spl","application/futuresplash"},
	{"src","application/x-wais-source"},
	{"sst","application/vnd.ms-pkicertstore"},
	{"stl","application/vnd.ms-pkistl"},
	{"stm","text/html"},
	{"svg","image/svg+xml"},
	{"sv4cpio","application/x-sv4cpio"},
	{"sv4crc","application/x-sv4crc"},
	{"swf","application/x-shockwave-flash"},
	{"t","application/x-troff"},
	{"tar","application/x-tar"},
	{"tcl","application/x-tcl"},
	{"tes","text/event-stream"},
	{"tex","application/x-tex"},
	{"texi","application/x-texinfo"},
	{"texinfo","application/x-texinfo"},
	{"tgz","application/x-compressed"},
	{"tif","image/tiff"},
	{"tiff","image/tiff"},
	{"tr","application/x-troff"},
	{"trm","application/x-msterminal"},
	{"tsv","text/tab-separated-values"},
	{"txt","text/plain"},
	{"uls","text/iuls"},
	{"action","text/html"},
	{"upload","application/x-ustar"},
	{"vcf","text/x-vcard"},
	{"vrml","x-world/x-vrml"},
	{"wav","audio/x-wav"},
	{"wcm","application/vnd.ms-works"},
	{"wdb","application/vnd.ms-works"},
	{"wks","application/vnd.ms-works"},
	{"wmf","application/x-msmetafile"},
	{"woff""application/x-woff"},
	{"wps","application/vnd.ms-works"},
	{"wri","application/x-mswrite"},
	{"wrl","x-world/x-vrml"},
	{"wrz","x-world/x-vrml"},
	{"xaf","x-world/x-vrml"},
	{"xbm","image/x-xbitmap"},
	{"xla","application/vnd.ms-excel"},
	{"xlc","application/vnd.ms-excel"},
	{"xlm","application/vnd.ms-excel"},
	{"xls","application/vnd.ms-excel"},
	{"xlt","application/vnd.ms-excel"},
	{"xlw","application/vnd.ms-excel"},
	{"xml","application/xml"},
	{"xof","x-world/x-vrml"},
	{"xpm","image/x-xpixmap"},
	{"xwd","image/x-xwindowdump"},
	{"z","application/x-compress"},
	{"zip","application/zip"},
	{ 0, 0 } // Marks end of list.
};

std::string extension_to_type(const std::string& extension) {

	if (extension.empty()) {
		return "application/octet-stream";
	}
	std::string s = boost::to_lower_copy(extension);
	for (mapping m : mappings) {
		if (m.extension == NULL) {
			return "application/octet-stream";
		} else if (m.extension == s) {
			if ("regex" == m.extension) {
				freshregx();
			}
			return m.mime_type;
		}
	}

	return "text/plain";
}

} // namespace mime_types
} // namespace server
} // namespace http
