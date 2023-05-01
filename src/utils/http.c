#include <windows.h>
#include <winhttp.h>

#include "http.h"

static BOOL gHttpIsInit = FALSE;
static HINTERNET gHttpSession = NULL;

static BOOL http_open_session() {
    const WCHAR *lpszProxy;
    LPWSTR lpszProxyBypass;
    DWORD dwAccessType;
    const WCHAR *pszProxyBypassW;
    WINHTTP_CURRENT_USER_IE_PROXY_CONFIG pProxyConfig;

    ZeroMemory(&pProxyConfig, sizeof(pProxyConfig));
    WinHttpGetIEProxyConfigForCurrentUser(&pProxyConfig);

    lpszProxy = pProxyConfig.lpszProxy;
    if (pProxyConfig.lpszProxy) {
        lpszProxyBypass = NULL;
        dwAccessType = WINHTTP_ACCESS_TYPE_NAMED_PROXY;

        if (pProxyConfig.lpszProxyBypass) {
            lpszProxyBypass = pProxyConfig.lpszProxyBypass;
        }

        pszProxyBypassW = lpszProxyBypass;
    } else {
        pszProxyBypassW = NULL;
        dwAccessType = WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY;
    }

    gHttpSession = WinHttpOpen(
        (LPCWSTR)L"e-AMUSEMENT CLOUD AGENT",
        dwAccessType,
        lpszProxy,
        pszProxyBypassW,
        WINHTTP_FLAG_ASYNC
    );

    if (gHttpSession == NULL) {
        return FALSE;
    }

    if (!WinHttpSetTimeouts(gHttpSession, 60000, 60000, 30000, 30000)) {
        WinHttpCloseHandle(gHttpSession);
        return FALSE;
    }

    return TRUE;
}

BOOL http_boot() {
    if (gHttpIsInit == TRUE) {
        return TRUE;
    }

    if (http_open_session() == FALSE) {
        return FALSE;
    }

    gHttpIsInit = TRUE;
    return TRUE;
}

void http_shutdown() {
    if (gHttpIsInit == FALSE) {
        return;
    }

    if (gHttpSession != NULL) {
        WinHttpCloseHandle(gHttpSession);
        gHttpSession = NULL;
    }

    gHttpIsInit = FALSE;
}
