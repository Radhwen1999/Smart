#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>

struct upload_status {
    const char *readptr;
    size_t sizeleft;
};

static size_t payload_source(void *ptr, size_t size, size_t nmemb, void *userp)
{
  struct upload_status *upload_ctx = (struct upload_status *)userp;
  const char *data;

  size_t bytes_to_copy = upload_ctx->sizeleft < size*nmemb ? upload_ctx->sizeleft : size*nmemb;
  bytes_to_copy = upload_ctx->sizeleft < 10 ? upload_ctx->sizeleft : 10;

  if(size*nmemb < 1)
    return 0;

  if(upload_ctx->sizeleft)
  {
    memcpy((char*)ptr, (char*)upload_ctx->readptr, bytes_to_copy);
    upload_ctx->readptr+=bytes_to_copy;
    upload_ctx->sizeleft-=bytes_to_copy;
    return bytes_to_copy;
  }

  return 0;
}




int send_mail(const char* to, const char* message,const char* mdp)
{
    CURL *curl;
    CURLcode res = CURLE_OK;
    struct curl_slist *recipients = NULL;
    struct upload_status upload_ctx;

    // TODO Change these
    const char* smtp_from       = "adem.boujnah@esprit.tn";
    const char* smtp_username   = "adem.boujnah@esprit.tn";
    const char* smtp_password   = "ADEMadem.123*";
    const char* smtp_server_url = "smtp://smtp.gmail.com:25";


    curl = curl_easy_init();
    if(curl)
    {
        // Time
        time_t rawtime;
        struct tm * timeinfo;
        char time_buffer[128];
        time(&rawtime);
        timeinfo = localtime (&rawtime);
        strftime (time_buffer, 128, "%a, %d %b %Y %H:%M:%S %z", timeinfo);
        // END Time

        // This is what our message will look like, but with details filled in.
        const char payload_template[] =
        "Date: %s\r\n"
        "To: %s\r\n"
        "From: %s\r\n"
        "Message-ID: <%s@example.com>\r\n"
        "Subject: Smart Esprit\r\n"
        "\r\n"
        "Votre Esprit ID est :%s\nVotre mot de passe est : %s\r\n\r\n";

        // TODO You must make this unique for every message sent.
        // Generate it according to spec.
        char message_id[] = "126cfbe1fd5413ba4d604c50a74bfc80471cec367b1604ade4d081f31c3f4f34";

        size_t payload_text_len = strlen(payload_template) +  
                                  strlen(time_buffer) +
                                  strlen(to) + strlen(smtp_from) +
                                  strlen(message_id) + strlen(message) + strlen(mdp)+ 1;

        char* payload_text = malloc(payload_text_len);

        memset(payload_text, 0, payload_text_len);

        sprintf(payload_text, payload_template, time_buffer, to,
                smtp_from, message_id, message,mdp);

        upload_ctx.readptr = payload_text;
        upload_ctx.sizeleft = (long)strlen(payload_text);

        /* Set username and password */
        curl_easy_setopt(curl, CURLOPT_USERNAME, smtp_username);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, smtp_password);

        curl_easy_setopt(curl, CURLOPT_URL, smtp_server_url);

        // If you are not using SSL/TLS you are safe commenting three lines below
        curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, smtp_from);

        recipients = curl_slist_append(recipients, to);

        // More recipients
        //recipients = curl_slist_append(recipients, CC);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
        curl_easy_setopt(curl, CURLOPT_READDATA, &upload_ctx);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        /* Send the message */
        res = curl_easy_perform(curl);

        /* Check for errors */
        if(res != CURLE_OK)
          printf("curl_easy_perform() failed %s\n", curl_easy_strerror(res));

        /* Free the list of recipients */
        curl_slist_free_all(recipients);

        /* Always cleanup */
        curl_easy_cleanup(curl);

        free(payload_text);
  }

  return (int)res;
}



int send_mail1(const char* to, const char* message,const char* mdp)
{
    CURL *curl;
    CURLcode res = CURLE_OK;
    struct curl_slist *recipients = NULL;
    struct upload_status upload_ctx;

    // TODO Change these
    const char* smtp_from       = "adem.boujnah@esprit.tn";
    const char* smtp_username   = "adem.boujnah@esprit.tn";
    const char* smtp_password   = "ADEMadem.123*";
    const char* smtp_server_url = "smtp://smtp.gmail.com:25";


    curl = curl_easy_init();
    if(curl)
    {
        // Time
        time_t rawtime;
        struct tm * timeinfo;
        char time_buffer[128];
        time(&rawtime);
        timeinfo = localtime (&rawtime);
        strftime (time_buffer, 128, "%a, %d %b %Y %H:%M:%S %z", timeinfo);
        // END Time

        // This is what our message will look like, but with details filled in.
        const char payload_template[] =
        "Date: %s\r\n"
        "To: %s\r\n"
        "From: %s\r\n"
        "Message-ID: <%s@example.com>\r\n"
        "Subject: Smart Esprit\r\n"
        "\r\n"
        "Alerte!\n le capteur num :%s\nDetécté au jour : %s\n est diffectueux\r\n\r\n";

        // TODO You must make this unique for every message sent.
        // Generate it according to spec.
        char message_id[] = "126cfbe1fd5413ba4d604c50a74bfc80471cec367b1604ade4d081f31c3f4f34";

        size_t payload_text_len = strlen(payload_template) +  
                                  strlen(time_buffer) +
                                  strlen(to) + strlen(smtp_from) +
                                  strlen(message_id) + strlen(message) + strlen(mdp)+ 1;

        char* payload_text = malloc(payload_text_len);

        memset(payload_text, 0, payload_text_len);

        sprintf(payload_text, payload_template, time_buffer, to,
                smtp_from, message_id, message,mdp);

        upload_ctx.readptr = payload_text;
        upload_ctx.sizeleft = (long)strlen(payload_text);

        /* Set username and password */
        curl_easy_setopt(curl, CURLOPT_USERNAME, smtp_username);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, smtp_password);

        curl_easy_setopt(curl, CURLOPT_URL, smtp_server_url);

        // If you are not using SSL/TLS you are safe commenting three lines below
        curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, smtp_from);

        recipients = curl_slist_append(recipients, to);

        // More recipients
        //recipients = curl_slist_append(recipients, CC);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
        curl_easy_setopt(curl, CURLOPT_READDATA, &upload_ctx);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        /* Send the message */
        res = curl_easy_perform(curl);

        /* Check for errors */
        if(res != CURLE_OK)
          printf("curl_easy_perform() failed %s\n", curl_easy_strerror(res));

        /* Free the list of recipients */
        curl_slist_free_all(recipients);

        /* Always cleanup */
        curl_easy_cleanup(curl);

        free(payload_text);
  }

  return (int)res;
}

int send_mail2(const char* to, const char* message,const char* mdp)
{
    CURL *curl;
    CURLcode res = CURLE_OK;
    struct curl_slist *recipients = NULL;
    struct upload_status upload_ctx;

    // TODO Change these
    const char* smtp_from       = "adem.boujnah@esprit.tn";
    const char* smtp_username   = "adem.boujnah@esprit.tn";
    const char* smtp_password   = "ADEMadem.123*";
    const char* smtp_server_url = "smtp://smtp.gmail.com:25";


    curl = curl_easy_init();
    if(curl)
    {
        // Time
        time_t rawtime;
        struct tm * timeinfo;
        char time_buffer[128];
        time(&rawtime);
        timeinfo = localtime (&rawtime);
        strftime (time_buffer, 128, "%a, %d %b %Y %H:%M:%S %z", timeinfo);
        // END Time

        // This is what our message will look like, but with details filled in.
        const char payload_template[] =
        "Date: %s\r\n"
        "To: %s\r\n"
        "From: %s\r\n"
        "Message-ID: <%s@example.com>\r\n"
        "Subject: Smart Esprit\r\n"
        "\r\n"
        "Alerte!\n le capteur num :%s\n au jour : %s\n a détecté un mouvement\r\n\r\n";

        // TODO You must make this unique for every message sent.
        // Generate it according to spec.
        char message_id[] = "126cfbe1fd5413ba4d604c50a74bfc80471cec367b1604ade4d081f31c3f4f34";

        size_t payload_text_len = strlen(payload_template) +  
                                  strlen(time_buffer) +
                                  strlen(to) + strlen(smtp_from) +
                                  strlen(message_id) + strlen(message) + strlen(mdp)+ 1;

        char* payload_text = malloc(payload_text_len);

        memset(payload_text, 0, payload_text_len);

        sprintf(payload_text, payload_template, time_buffer, to,
                smtp_from, message_id, message,mdp);

        upload_ctx.readptr = payload_text;
        upload_ctx.sizeleft = (long)strlen(payload_text);

        /* Set username and password */
        curl_easy_setopt(curl, CURLOPT_USERNAME, smtp_username);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, smtp_password);

        curl_easy_setopt(curl, CURLOPT_URL, smtp_server_url);

        // If you are not using SSL/TLS you are safe commenting three lines below
        curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, smtp_from);

        recipients = curl_slist_append(recipients, to);

        // More recipients
        //recipients = curl_slist_append(recipients, CC);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
        curl_easy_setopt(curl, CURLOPT_READDATA, &upload_ctx);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        /* Send the message */
        res = curl_easy_perform(curl);

        /* Check for errors */
        if(res != CURLE_OK)
          printf("curl_easy_perform() failed %s\n", curl_easy_strerror(res));

        /* Free the list of recipients */
        curl_slist_free_all(recipients);

        /* Always cleanup */
        curl_easy_cleanup(curl);

        free(payload_text);
  }

  return (int)res;
}
int send_mail3(const char* to, const char* message,const char* mdp)
{
    CURL *curl;
    CURLcode res = CURLE_OK;
    struct curl_slist *recipients = NULL;
    struct upload_status upload_ctx;

    // TODO Change these
    const char* smtp_from       = "adem.boujnah@esprit.tn";
    const char* smtp_username   = "adem.boujnah@esprit.tn";
    const char* smtp_password   = "ADEMadem.123*";
    const char* smtp_server_url = "smtp://smtp.gmail.com:25";


    curl = curl_easy_init();
    if(curl)
    {
        // Time
        time_t rawtime;
        struct tm * timeinfo;
        char time_buffer[128];
        time(&rawtime);
        timeinfo = localtime (&rawtime);
        strftime (time_buffer, 128, "%a, %d %b %Y %H:%M:%S %z", timeinfo);
        // END Time

        // This is what our message will look like, but with details filled in.
        const char payload_template[] =
        "Date: %s\r\n"
        "To: %s\r\n"
        "From: %s\r\n"
        "Message-ID: <%s@example.com>\r\n"
        "Subject: Smart Esprit\r\n"
        "\r\n"
       "Alerte!\n le capteur num :%s\n au jour : %s\n a détecté une fumée\r\n\r\n";

        // TODO You must make this unique for every message sent.
        // Generate it according to spec.
        char message_id[] = "126cfbe1fd5413ba4d604c50a74bfc80471cec367b1604ade4d081f31c3f4f34";

        size_t payload_text_len = strlen(payload_template) +  
                                  strlen(time_buffer) +
                                  strlen(to) + strlen(smtp_from) +
                                  strlen(message_id) + strlen(message) + strlen(mdp)+ 1;

        char* payload_text = malloc(payload_text_len);

        memset(payload_text, 0, payload_text_len);

        sprintf(payload_text, payload_template, time_buffer, to,
                smtp_from, message_id, message,mdp);

        upload_ctx.readptr = payload_text;
        upload_ctx.sizeleft = (long)strlen(payload_text);

        /* Set username and password */
        curl_easy_setopt(curl, CURLOPT_USERNAME, smtp_username);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, smtp_password);

        curl_easy_setopt(curl, CURLOPT_URL, smtp_server_url);

        // If you are not using SSL/TLS you are safe commenting three lines below
        curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, smtp_from);

        recipients = curl_slist_append(recipients, to);

        // More recipients
        //recipients = curl_slist_append(recipients, CC);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
        curl_easy_setopt(curl, CURLOPT_READDATA, &upload_ctx);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        /* Send the message */
        res = curl_easy_perform(curl);

        /* Check for errors */
        if(res != CURLE_OK)
          printf("curl_easy_perform() failed %s\n", curl_easy_strerror(res));

        /* Free the list of recipients */
        curl_slist_free_all(recipients);

        /* Always cleanup */
        curl_easy_cleanup(curl);

        free(payload_text);
  }

  return (int)res;
}


int send_maila(const char* to, const char* message,const char* mdp)
{
    CURL *curl;
    CURLcode res = CURLE_OK;
    struct curl_slist *recipients = NULL;
    struct upload_status upload_ctx;

    // TODO Change these
    const char* smtp_from       = "adem.boujnah@esprit.tn";
    const char* smtp_username   = "adem.boujnah@esprit.tn";
    const char* smtp_password   = "ADEMadem.123*";
    const char* smtp_server_url = "smtp://smtp.gmail.com:25";


    curl = curl_easy_init();
    if(curl)
    {
        // Time
        time_t rawtime;
        struct tm * timeinfo;
        char time_buffer[128];
        time(&rawtime);
        timeinfo = localtime (&rawtime);
        strftime (time_buffer, 128, "%a, %d %b %Y %H:%M:%S %z", timeinfo);
        // END Time

        // This is what our message will look like, but with details filled in.
        const char payload_template[] =
        "Date: %s\r\n"
        "To: %s\r\n"
        "From: %s\r\n"
        "Message-ID: <%s@example.com>\r\n"
        "Subject: Smart Esprit\r\n"
        "\r\n"
        "L'identifiant %s a envoyé une reclamation concernant %s\r\n\r\n";

        // TODO You must make this unique for every message sent.
        // Generate it according to spec.
        char message_id[] = "126cfbe1fd5413ba4d604c50a74bfc80471cec367b1604ade4d081f31c3f4f34";

        size_t payload_text_len = strlen(payload_template) +  
                                  strlen(time_buffer) +
                                  strlen(to) + strlen(smtp_from) +
                                  strlen(message_id) + strlen(message) + strlen(mdp)+ 1;

        char* payload_text = malloc(payload_text_len);

        memset(payload_text, 0, payload_text_len);

        sprintf(payload_text, payload_template, time_buffer, to,
                smtp_from, message_id, message,mdp);

        upload_ctx.readptr = payload_text;
        upload_ctx.sizeleft = (long)strlen(payload_text);

        /* Set username and password */
        curl_easy_setopt(curl, CURLOPT_USERNAME, smtp_username);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, smtp_password);

        curl_easy_setopt(curl, CURLOPT_URL, smtp_server_url);

        // If you are not using SSL/TLS you are safe commenting three lines below
        curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, smtp_from);

        recipients = curl_slist_append(recipients, to);

        // More recipients
        //recipients = curl_slist_append(recipients, CC);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
        curl_easy_setopt(curl, CURLOPT_READDATA, &upload_ctx);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        /* Send the message */
        res = curl_easy_perform(curl);

        /* Check for errors */
        if(res != CURLE_OK)
          printf("curl_easy_perform() failed %s\n", curl_easy_strerror(res));

        /* Free the list of recipients */
        curl_slist_free_all(recipients);

        /* Always cleanup */
        curl_easy_cleanup(curl);

        free(payload_text);
  }

  return (int)res;
}



        











