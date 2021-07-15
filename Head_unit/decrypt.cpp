#include"decrypt.h"


std::vector<BYTE> readFile(std::string filename)
{
    // open the file:
    std::ifstream file(filename, std::ios::binary);

    file.unsetf(std::ios::skipws);

    // get its size:
    std::streampos fileSize;

    file.seekg(0, std::ios::end);
    fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // reserve capacity
    std::vector<BYTE> vec;
    vec.reserve(fileSize);

    // read the data:
    vec.insert(vec.begin(),std::istream_iterator<BYTE>(file), std::istream_iterator<BYTE>());

    return vec;
}


void aes_decrypt(std::string path)
{

	byte key[ CryptoPP::AES::DEFAULT_KEYLENGTH ], iv[ CryptoPP::AES::BLOCKSIZE ];
    memset( key, 0x00, CryptoPP::AES::DEFAULT_KEYLENGTH );
    memset( iv, 0x00, CryptoPP::AES::BLOCKSIZE );

    std::vector<BYTE> data;

	std::string enc_path = path;
    data=readFile(enc_path);
    std::string ciphertext(data.begin(),data.end());

    std::string decryptedtext;



    // Decrypt
    //
    CryptoPP::AES::Decryption aesDecryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption( aesDecryption, iv );

    CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink( decryptedtext ) );
    stfDecryptor.Put( reinterpret_cast<const unsigned char*>( ciphertext.c_str() ), ciphertext.size() );
    stfDecryptor.MessageEnd();

    //
    // Dump Decrypted Text
    //
    std::cout << "Decrypted Text (" << decryptedtext.size()-1 << " bytes)" << std::endl;
    std::cout << std::endl << std::endl;

    std::ofstream out;
	out.open(enc_path);
    out<<(decryptedtext);
    out.close();

   std::cout <<"Successfully Decrypted";


}
