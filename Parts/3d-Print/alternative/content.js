let filters = []

chrome.storage.sync.get('filterStatus', (data) => {
    enabled = data.filterStatus;
    if (enabled) {
        chrome.storage.sync.get('filters', (data) => {
            popupFilters = data.filters[0];
            scrollFilters = data.filters[1];
            queryFilters = data.filters[2]
            // console.log(queryFilters);
            tryBlockPopups(popupFilters, scrollFilters, queryFilters);
        });
    }
});

tries = 0

tryBlockPopups = (popupFilters, scrollFilters, queryFilters) => {
    // let css = "body { overflow: scroll !important }"; // re-enable scrolling
    let css = "";
    let head = document.head || document.getElementsByTagName('head')[0];
    let style = document.createElement('style');

    // remove popup modals
    for (filter of popupFilters) {
        css += filter + " { display: none !important } ";
    }

    // re-enable scrolling
    enableScrolling(scrollFilters, queryFilters);

    head.appendChild(style);

    style.type = 'text/css';
    if (style.styleSheet) {
        // This is required for IE8 and below.
        style.styleSheet.cssText = css;
    } else {
        style.appendChild(document.createTextNode(css));
    }
}

let enableScrolling = (scrollFilters) => {
    setTimeout(() => {
        tries++;
        let canScroll = false;
        if (document.getElementsByTagName("HTML")[0].style.overflow == "hidden") {
            document.getElementsByTagName("HTML")[0].style.overflow = "";
            canScroll = true;
        }
        if (document.getElementsByTagName("HTML")[0].style.overflowY == "hidden") {
            document.getElementsByTagName("HTML")[0].style.overflowY = "";
            canScroll = true;
        }
        if (document.body.style.overflow == "hidden") { // case: <body style="overflow:hidden">
            document.body.style.overflow = "";
            canScroll = true;
        }
        if (document.body.style.overflowY == "hidden") { // case: <body style="overflow-y:hidden">
            document.body.style.overflowY = "";
            canScroll = true;
        }
        // case: scroll-disable is a css class, or query filters are present
        for (filter of scrollFilters) {
            if (document.getElementsByClassName(filter).length > 0) {
                let elements = document.getElementsByClassName(filter);
                while (elements.length > 0) {
                    elements[0].classList.remove(filter);
                }
                canScroll = true;
                break;
            }
        }
        for (filter of queryFilters) {
            if (document.querySelector(filter.value)) {
                if (filter.type == "scroll") {
                    document.querySelector(filter.value).style.overflow = "scroll";
                } else {
                    document.querySelector(filter.value).style.display = "none";
                }
                canScroll = true;
            }
        }
        //console.log(tries);
        // console.log(canScroll);
        if (canScroll == true) {
            // console.log("setting badge...");
            chrome.extension.sendMessage({ badge: "1" }); // send message to background.js to display badge
        } else if (tries < 20) {
            enableScrolling(scrollFilters);
        }
    }, 500);
}

// tryBlockPopups = (filterNames) => {
//     setTimeout(() => {
//         tries++;
//         let blocked = false;
//         for (filter of filterNames) {
//             if (document.querySelector(filter)) {
//                 document.querySelector(filter).style.display = "none";
//                 document.body.style.overflow = "scroll";
//                 blocked = true;
//             }
//         }
//         if (blocked == false && tries < 20) {
//             tryBlockPopups(filterNames);
//         }
//     }, 250);
// }